/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsacquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 11:45:11 by fsacquin          #+#    #+#             */
/*   Updated: 2021/04/17 15:50:30 by fsacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	screen_manager(t_tree *tree)
{
	if (tree->image.img != 0)
		mlx_destroy_image(tree->vars.mlx, tree->image.img);
	tree->image.img = mlx_new_image(tree->vars.mlx,
			tree->parsing.res_x, tree->parsing.res_y);
	tree->image.addr = mlx_get_data_addr(tree->image.img,
			&tree->image.bits_per_pixel, &tree->image.line_length,
			&tree->image.endian);
	raycasting(tree);
	return (0);
}

int	screen_manager_2(t_tree *tree)
{
	mlx_put_image_to_window(tree->vars.mlx,
		tree->vars.win, tree->image.img, 0, 0);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
