/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsacquin <fsacquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:25:22 by fsacquin          #+#    #+#             */
/*   Updated: 2021/06/07 16:25:31 by fsacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	calc_delta_dist(t_tree *tree)
{
	if (tree->ray.ray_dir_y == 0)
		tree->ray.delta_dist_x = 0;
	else
	{
		if (tree->ray.ray_dir_x == 0)
			tree->ray.delta_dist_x = 1;
		else
			tree->ray.delta_dist_x = fabs(1 / tree->ray.ray_dir_x);
	}
	if (tree->ray.ray_dir_x == 0)
		tree->ray.delta_dist_y = 0;
	else
	{
		if (tree->ray.ray_dir_y == 0)
			tree->ray.delta_dist_y = 1;
		else
			tree->ray.delta_dist_y = fabs(1 / tree->ray.ray_dir_y);
	}
}

void	calc_side_dist(t_tree *tree)
{
	if (tree->ray.ray_dir_x < 0)
	{
		tree->ray.step_x = -1;
		tree->ray.side_dist_x = (tree->image.play_x
				- tree->ray.map_x) * tree->ray.delta_dist_x;
	}
	else
	{
		tree->ray.step_x = 1;
		tree->ray.side_dist_x = (tree->ray.map_x + 1.0 - tree->image.play_x)
			* tree->ray.delta_dist_x;
	}
	if (tree->ray.ray_dir_y < 0)
	{
		tree->ray.step_y = -1;
		tree->ray.side_dist_y = (tree->image.play_y
				- tree->ray.map_y) * tree->ray.delta_dist_y;
	}
	else
	{
		tree->ray.step_y = 1;
		tree->ray.side_dist_y = (tree->ray.map_y + 1.0 - tree->image.play_y)
			* tree->ray.delta_dist_y;
	}
}

void	ray_until_wall(t_tree *tree)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (tree->ray.side_dist_x < tree->ray.side_dist_y)
		{
			tree->ray.side_dist_x += tree->ray.delta_dist_x;
			tree->ray.map_x += tree->ray.step_x;
			tree->ray.side = 0;
		}
		else
		{
			tree->ray.side_dist_y += tree->ray.delta_dist_y;
			tree->ray.map_y += tree->ray.step_y;
			tree->ray.side = 1;
		}
		if (tree->parsing.lab[ft_strlen_array(tree->parsing.lab)
				- tree->ray.map_y - 1][tree->ray.map_x] == '1')
			hit = 1;
	}
}

void	draw_calc(t_tree *tree)
{
	if (tree->ray.side == 0)
		tree->ray.perp_wall_dist = (tree->ray.map_x - tree->image.play_x
				+ (1 - tree->ray.step_x) / 2) / tree->ray.ray_dir_x;
	else
		tree->ray.perp_wall_dist = (tree->ray.map_y - tree->image.play_y
				+ (1 - tree->ray.step_y) / 2) / tree->ray.ray_dir_y;
	tree->ray.line_height = (int)(tree->parsing.res_y
			/ tree->ray.perp_wall_dist);
	tree->ray.draw_start = -tree->ray.line_height / 2 + tree->parsing.res_y / 2;
	if (tree->ray.draw_start < 0)
		tree->ray.draw_start = 0;
	tree->ray.draw_end = tree->ray.line_height / 2 + tree->parsing.res_y / 2;
	if (tree->ray.draw_end >= tree->parsing.res_y)
		tree->ray.draw_end = tree->parsing.res_y - 1;
	if (tree->ray.side == 0)
		tree->ray.wall_x = tree->image.play_y + tree->ray.perp_wall_dist
			* tree->ray.ray_dir_y;
	else
		tree->ray.wall_x = tree->image.play_x + tree->ray.perp_wall_dist
			* tree->ray.ray_dir_x;
}

void	tex_select(t_tree *tree)
{
	if (tree->ray.side == 0)
	{
		if (tree->ray.ray_dir_x < 0)
			tree->ray.tex_num = 'W';
		else
			tree->ray.tex_num = 'E';
	}
	else
	{
		if (tree->ray.ray_dir_y < 0)
			tree->ray.tex_num = 'S';
		else
			tree->ray.tex_num = 'N';
	}
}
