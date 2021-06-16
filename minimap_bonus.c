/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsacquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 10:15:31 by fsacquin          #+#    #+#             */
/*   Updated: 2021/06/08 10:15:35 by fsacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
/*
void	ft_draw_line(int x, int draw_start, int draw_end,
		int trgb, t_tree *tree)
{
	int		i;

	i = 0;
	while (i < draw_start)
	{
		my_mlx_pixel_put(&tree->image, x, i, 0x0099FFFF);
		i++;
	}
	while (i < draw_end)
	{
		my_mlx_pixel_put(&tree->image, x, i, trgb);
		i++;
	}
	while (i < tree->parsing.res_y)
	{
		my_mlx_pixel_put(&tree->image, x, i, 0x00663300);
		i++;
	}
}

void	dividing_walls(t_tree *tree)
{
	int		lines;
	int		lin_len;
	int		lab_x;
	int		lab_y;

	lines = ft_strlen_array(tree->parsing.lab);
	lin_len = ft_strlen(tree->parsing.lab[0]);
	lab_x = 0;
	lab_y = 0;
	while (tree->parsing.lab[lab_x])
	{
		lab_y = 0;
		while (tree->parsing.lab[lab_x][lab_y])
		{
			coloring_lab_cubes(lab_x, lab_y, lines, lin_len);
			lab_y++;
		}
		lab_x++;
	}
}

void	coloring_lab_cubes(int lab_x, int lab_y, int lines,
		int lin_len, t_tree *tree)
{
	int		i;
	int		j;

	if (tree->parsing.lab[lab_x][lab_y] == '1'
		|| tree->parsing.lab[lab_x][lab_y] == ' ')
	{
		i = ((tree->parsing.res_x / lin_len) * lab_y) - 1;
		while (i++ < (tree->parsing.res_x / lin_len) * (lab_y + 1))
		{
			j = ((tree->parsing.res_y / lines) * lab_x) - 1;
			while (j++ < ((tree->parsing.res_y / lines) * (lab_x + 1)))
				my_mlx_pixel_put(&tree->image, i, j, 0x00000000);
		}
	}
	else
	{
		i = ((tree->parsing.res_x / lin_len) * lab_y) - 1;
		while (i++ < (tree->parsing.res_x / lin_len) * (lab_y + 1))
		{
			j = ((tree->parsing.res_y / lines) * lab_x) - 1;
			while (j++ < (tree->parsing.res_y / lines) * (lab_x + 1))
				my_mlx_pixel_put(&tree->image, i, j, 0x00FFFFFF);
		}
	}
}
*/