/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsacquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:15:43 by fsacquin          #+#    #+#             */
/*   Updated: 2021/06/07 16:28:08 by fsacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_camera_plane(int x, t_tree *tree)
{
	double	camera_x;

	camera_x = 2 * x / (double)(tree->parsing.res_x) - 1;
	tree->ray.ray_dir_x = tree->image.dir_x + tree->image.plane_x * camera_x;
	tree->ray.ray_dir_y = tree->image.dir_y + tree->image.plane_y * camera_x;
	tree->ray.map_x = (int)tree->image.play_x;
	tree->ray.map_y = (int)tree->image.play_y;
}

int	draw_ceiling(int x, int y, t_tree *tree)
{
	while (y < tree->ray.draw_start)
	{
		my_mlx_pixel_put(&tree->image, x, y, tree->parsing.ceiling_color);
		y++;
	}
	return (y);
}

int	draw_tex(int x, int y, t_tree *tree)
{

	while (y < tree->ray.draw_end)
	{
		tree->ray.tex_y = (int)(tree->ray.tex_pos);
		tree->ray.tex_pos += tree->ray.step;
		if (tree->ray.tex_num == 'N')
			tree->ray.color = tree->texture.tex_NO[tree->texture.n_tex_h
				* tree->ray.tex_y + tree->ray.tex_x];
		else if (tree->ray.tex_num == 'S')
			tree->ray.color = tree->texture.tex_SO[tree->texture.s_tex_h
				* tree->ray.tex_y + tree->ray.tex_x];
		else if (tree->ray.tex_num == 'E')
		{
			tree->ray.color = tree->texture.tex_EA[tree->texture.e_tex_h
				* tree->ray.tex_y + tree->ray.tex_x];
		}
		else if (tree->ray.tex_num == 'W')
			tree->ray.color = tree->texture.tex_WE[tree->texture.w_tex_h
				* tree->ray.tex_y + tree->ray.tex_x];
		my_mlx_pixel_put(&tree->image, x, y, tree->ray.color);
		y++;
	}
	return (y);
}

int	draw_floor(int x, int y, t_tree *tree)
{
	while (y < tree->parsing.res_y)
	{
		my_mlx_pixel_put(&tree->image, x, y, tree->parsing.floor_color);
		y++;
	}
	return (y);
}

void	raycasting(t_tree *tree)
{
	int		x;
	int		y;

	x = 0;
	while (x < tree->parsing.res_x)
	{
		init_camera_plane(x, tree);
		calc_delta_dist(tree);
		calc_side_dist(tree);
		ray_until_wall(tree);
		draw_calc(tree);
		tree->ray.wall_x -= floor(tree->ray.wall_x);
		tex_select(tree);
		if (tree->ray.tex_num == 'N')
			tree->ray.step = 1.0 * tree->texture.n_tex_w / tree->ray.line_height;
		else if (tree->ray.tex_num == 'S')
			tree->ray.step = 1.0 * tree->texture.s_tex_w / tree->ray.line_height;
		else if (tree->ray.tex_num == 'E')
			tree->ray.step = 1.0 * tree->texture.e_tex_w / tree->ray.line_height;
		else if (tree->ray.tex_num == 'W')
			tree->ray.step = 1.0 * tree->texture.w_tex_w / tree->ray.line_height;
		tree->ray.tex_pos = (tree->ray.draw_start - (tree->parsing.res_y / 2)
				+ (tree->ray.line_height / 2)) * tree->ray.step;
		y = 0;
		y = draw_ceiling(x, y, tree);
		y = draw_tex(x, y, tree);
		y = draw_floor(x, y, tree);
		x++;
	}
}
