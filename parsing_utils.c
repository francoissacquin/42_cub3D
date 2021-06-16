/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsacquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 17:13:51 by fsacquin          #+#    #+#             */
/*   Updated: 2021/06/06 15:33:37 by fsacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	first_wall(char *str, int c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '0')
		{
			printf("Error\n breach in labyrinth external wall\n");
			return (-1);
		}
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	last_wall(char *str, int c)
{
	int		i;

	i = ft_strlen(str);
	i--;
	while (i >= 0)
	{
		if (str[i] == '0')
		{
			printf("Error\n breach in labyrinth external wall\n");
			return (-1);
		}
		if (str[i] == c)
			return (i);
		i--;
	}
	return (-1);
}

size_t	ft_strlen_array(char **array)
{
	size_t	i;

	i = 0;
	while (array[i] != NULL)
		i++;
	return (i);
}

/*
** same thing here, we make a small int tab to host 2 variables into one for
** norm reasons
** tab[0] = line_len or len : maximum length line of the map. 
** Is used as map width.
** tab[1] = line : number of lines of the map. Is used as map height.
*/
int	is_boundary_wall_alone(int x, int y, int *tab, t_tree *tree)
{
	int	res;

	res = 0;
	if (x == 0)
		res = n_wall_check(y, tab[0], tree);
	else if (x == tab[1] - 1)
		res = s_wall_check(y, tab[0], tab[1], tree);
	else if (y == 0)
	{
		if (tree->parsing.lab[x - 1][0] != '1'
			&& tree->parsing.lab[x + 1][0] != '1' && tree->parsing.lab[x][1])
			return (1);
	}
	else if (y == tab[0])
	{
		if (tree->parsing.lab[x - 1][tab[0]] != '1' && tree->parsing.lab[x + 1]
				[tab[0]] != '1' && tree->parsing.lab[x][tab[0] - 1])
			return (1);
	}
	return (res);
}

int	is_char_not_inside_walls(int x, int y, t_tree *tree)
{
	if (!(ft_strrchr("012NSEW", tree->parsing.lab[x][y - 1])))
		return (1);
	if (!(ft_strrchr("012NSEW", tree->parsing.lab[x][y + 1])))
		return (1);
	if (!(ft_strrchr("012NSEW", tree->parsing.lab[x - 1][y])))
		return (1);
	if (!(ft_strrchr("012NSEW", tree->parsing.lab[x + 1][y])))
		return (1);
	return (0);
}
