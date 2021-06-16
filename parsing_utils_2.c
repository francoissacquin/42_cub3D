/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsacquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 18:28:15 by fsacquin          #+#    #+#             */
/*   Updated: 2021/06/02 18:28:19 by fsacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	assign_texture(char **res_split, char c, char *str, t_tree *tree)
{
	if (c == 'N')
	{
		tree->parsing.n_tex_path = ft_strdup((const char *)res_split[1]);
		verify_texture_path(tree, res_split, str, tree->parsing.n_tex_path);
	}
	else if (c == 'W')
	{
		tree->parsing.w_tex_path = ft_strdup((const char *)res_split[1]);
		verify_texture_path(tree, res_split, str, tree->parsing.w_tex_path);
	}
	else if (c == 'E')
	{
		tree->parsing.e_tex_path = ft_strdup((const char *)res_split[1]);
		verify_texture_path(tree, res_split, str, tree->parsing.e_tex_path);
	}
	else if (c == 'S')
	{
		tree->parsing.s_tex_path = ft_strdup((const char *)res_split[1]);
		verify_texture_path(tree, res_split, str, tree->parsing.s_tex_path);
	}
	else
		error_central_parsing(8, res_split, str, tree);
}

void	verify_texture_path(t_tree *tree, char **res_split, char *error, char *str)
{
	int	i;

	i = ft_strlen(str);
	if (!(&str[i - 4] == ft_strnstr((char const *)str, ".xpm", i)))
		error_central_parsing(10, res_split, error, tree);
}

void	skip_lines(int start_line, int fd)
{
	int		x;
	int		j;
	char	*str;

	x = 0;
	j = get_next_line(fd, &str);
	while ((j > 0) && x < (start_line - 1))
	{
		free(str);
		str = 0;
		x++;
		j = get_next_line(fd, &str);
	}
	free(str);
}

/*
** same thing here, we make a small int tab to host 2 variables into one for
** norm reasons
** tab[0] = line_len : maximum length line of the map. Is used as map width
** tab[1] = line : number of lines of the map. Is used as map height.
*/
void	verify_lab_line(int x, int *starting_pos_count, int *tab, t_tree *tree)
{
	int	y;

	y = 0;
	while (tree->parsing.lab[x][y])
	{
		if (tree->parsing.lab[x][y] == '1')
			if (is_boundary_wall_alone(x, y, tab, tree))
				error_central_verify_labyrinth(1, tree);
		if (tree->parsing.lab[x][y] == '0'
				|| ft_strrchr("NSEW", tree->parsing.lab[x][y]))
		{
			if (x == 0 || x == tab[1] || y == 0 || y == tab[0])
				error_central_verify_labyrinth(2, tree);
			else if (is_char_not_inside_walls(x, y, tree))
				error_central_verify_labyrinth(3, tree);
		}
		if (ft_strrchr("NSEW", tree->parsing.lab[x][y]))
		{
			(*starting_pos_count)++;
			tree->parsing.starting_x = x;
			tree->parsing.starting_y = y;
		}
		y++;
	}
}

char	*ft_strnstr(const char *str, const char *to_find, size_t length)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (to_find[0] == '\0')
	{
		return ((char *)str);
	}
	while (str[i] && i < length)
	{
		j = 0;
		while (str[i + j] == to_find[j] && ((i + j) < length))
		{
			if (to_find[j + 1] == '\0')
			{
				return ((char *)str + i);
			}
			j++;
		}
		i++;
	}
	return (0);
}
