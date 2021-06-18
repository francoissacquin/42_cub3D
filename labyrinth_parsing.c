/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   labyrinth_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsacquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 17:12:49 by fsacquin          #+#    #+#             */
/*   Updated: 2021/03/11 17:12:51 by fsacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*
** You will find in the following function an int table with the corresponding
** variables :
** tab[0] = line : number of lines of the map
** tab[1] = line_len : length of the longest line of the map
** tab[2] = left_shift : minimum number of space present in front of a map line
** tab[3] = start_line : starting line number of the map in the .cub file
*/
void	lab_parsing_main(char *str, int lab_start_line, t_tree *tree)
{
	int		i;
	int		tab[4];

	i = 0;
	tab[0] = 1;
	tab[1] = (ft_strlen(str) - (ft_strlen(str) - last_wall(str, '1')));
	tab[2] = first_wall(str, '1');
	free(str);
	i = get_next_line(tree->parsing.fd, &str);
	while (i > 0)
	{
		lab_parsing_plus(str, &tab[1], &tab[2], tree);
		tab[0]++;
		free(str);
		i = get_next_line(tree->parsing.fd, &str);
	}
	free(str);
	close(tree->parsing.fd);
	tree->parsing.fd = 0;
	tab[3] = lab_start_line;
	assign_labyrinth(tab, tree);
}

void	lab_parsing_plus(char *str, int *biggest_len,
		int *left_shift, t_tree *tree)
{
	int	i;
	int	count_1;

	i = 0;
	count_1 = 0;
	while (str[i])
	{
		if (!(ft_strrchr("01NSEW \n", str[i])))
			error_central_labyrinth_parsing(1, str, tree);
		if (str[i] == '1')
			count_1++;
		i++;
	}
	if (count_1 != 0)
	{
		if (*biggest_len < (int)(ft_strlen(str)
			- (ft_strlen(str) - last_wall(str, '1'))))
			*biggest_len = (int)(ft_strlen(str)
					- (ft_strlen(str) - last_wall(str, '1')));
		if (*left_shift > first_wall(str, '1'))
			*left_shift = first_wall(str, '1');
	}
	else
		error_central_labyrinth_parsing(4, str, tree);
}

/*
** You will find in the following function an int table with the corresponding
** variables :
** tab[0] = line : number of lines of the map (can also be called map height)
** tab[1] = line_len : length of the longest line of the map
** tab[2] = left_shift : minimum number of space present in front of a map line
** tab[3] = start_line : starting line number of the map in the .cub file
*/
void	assign_labyrinth(int *tab, t_tree *tree)
{
	tree->parsing.fd = open((char const *)tree->parsing.file_path, O_RDONLY);
	if (tree->parsing.fd == -1)
		error_central_parsing(1, 0, 0, tree);
	tree->parsing.lab = (char **)malloc(sizeof(char *) * ((tab[0] + 1)));
	if (tree->parsing.lab == NULL)
		error_central_labyrinth_parsing(3, 0, tree);
	tree->parsing.lab[tab[0]] = NULL;
	skip_lines(tab[3], tree->parsing.fd);
	assign_lab_lines(tab[0], tab[1], tab[2], tree);
	verify_labyrinth(tab[1], tab[0], tree);
}

void	assign_lab_lines(int line, int line_len, int left_shift, t_tree *tree)
{
	int		x;
	int		j;
	int		y;
	char	*str;

	str = 0;
	x = 0;
	while ((get_next_line(tree->parsing.fd, &str)) > 0 && x < line)
	{
		tree->parsing.lab[x] = (char *)malloc(sizeof(char)
				* ((line_len - left_shift) + 2));
		y = 0;
		j = left_shift;
		while (str[j])
			tree->parsing.lab[x][y++] = str[j++];
		while (y < (line_len - left_shift + 1))
			tree->parsing.lab[x][y++] = ' ';
		tree->parsing.lab[x][line_len - left_shift + 1] = '\0';
		free(str);
		str = 0;
		x++;
	}
	clear_parsing(str, tree);
	tree->parsing.lab[x] = NULL;
}

/*
** Same thing here, we make a small int tab to host 2 variables into one for
** norm reasons
** tab[0] = line_len : maximum length line of the map. Is used as map width
** tab[1] = line : number of lines of the map. Is used as map height.
*/
void	verify_labyrinth(int line_len, int line, t_tree *tree)
{
	int		x;
	int		starting_pos_count;
	int		tab[2];

	starting_pos_count = 0;
	x = 0;
	tab[0] = line_len;
	tab[1] = line;
	while (tree->parsing.lab[x] != 0 && x < line)
	{
		verify_lab_line(x, &starting_pos_count, tab, tree);
		x++;
	}
	if (starting_pos_count != 1)
		error_central_verify_labyrinth(4, tree);
	tree->parsing.start_dir
		= tree->parsing.lab[tree->parsing.starting_x][tree->parsing.starting_y];
}
