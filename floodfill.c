/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsacquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 15:26:27 by fsacquin          #+#    #+#             */
/*   Updated: 2021/03/12 15:26:29 by fsacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_floodfill(t_tree *tree)
{
	tree->parsing.lab[tree->parsing.starting_x][tree->parsing.starting_y] = '0';
	floodfill(tree->parsing.starting_x, tree->parsing.starting_y, 4, tree);
	check_post_floodfill(tree);
	undo_floodfill(tree->parsing.starting_x, tree->parsing.starting_y, 0, tree);
	tree->parsing.lab[tree->parsing.starting_x][tree->parsing.starting_y]
		= tree->parsing.start_dir;
}

void	floodfill(int x, int y, int newnum, t_tree *tree)
{
	if (get_pixel(x, y, tree) == 0)
	{
		putpixel(x, y, newnum, tree);
		floodfill(x + 1, y, newnum, tree);
		floodfill(x - 1, y, newnum, tree);
		floodfill(x, y + 1, newnum, tree);
		floodfill(x, y - 1, newnum, tree);
	}
}

void	undo_floodfill(int x, int y, int newnum, t_tree *tree)
{
	if (get_pixel(x, y, tree) == 4)
	{
		putpixel(x, y, newnum, tree);
		undo_floodfill(x + 1, y, newnum, tree);
		undo_floodfill(x - 1, y, newnum, tree);
		undo_floodfill(x, y + 1, newnum, tree);
		undo_floodfill(x, y - 1, newnum, tree);
	}
}

void	check_post_floodfill(t_tree *tree)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tree->parsing.lab[i])
	{
		j = 0;
		while (tree->parsing.lab[i][j])
		{
			if (tree->parsing.lab[i][j] == '0')
				error_central_verify_labyrinth(5, tree);
			j++;
		}
		i++;
	}
}
