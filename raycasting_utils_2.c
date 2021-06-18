/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsacquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 16:45:32 by fsacquin          #+#    #+#             */
/*   Updated: 2021/06/18 16:45:34 by fsacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	tex_step_calc(t_tree *tree)
{
	if (tree->ray.tex_num == 'N')
		tree->ray.step = 1.0 * tree->texture.n_tex_h / tree->ray.line_height;
	else if (tree->ray.tex_num == 'S')
		tree->ray.step = 1.0 * tree->texture.s_tex_h / tree->ray.line_height;
	else if (tree->ray.tex_num == 'E')
		tree->ray.step = 1.0 * tree->texture.e_tex_h / tree->ray.line_height;
	else if (tree->ray.tex_num == 'W')
		tree->ray.step = 1.0 * tree->texture.w_tex_h / tree->ray.line_height;
	tree->ray.tex_pos = (tree->ray.draw_start - (tree->parsing.res_y / 2)
			+ (tree->ray.line_height / 2)) * tree->ray.step;
}

void	tex_x_calc(t_tree *tree)
{
	if (tree->ray.side == 0)
	{
		if (tree->ray.ray_dir_x < 0)
			tree->ray.tex_x = (int)(tree->ray.wall_x
					* (double)(tree->texture.w_tex_w));
		else
		{
			tree->ray.tex_x = (int)(tree->ray.wall_x
					* (double)(tree->texture.e_tex_w));
			tree->ray.tex_x = tree->texture.e_tex_w - tree->ray.tex_x - 1;
		}
	}
	else
	{
		if (tree->ray.ray_dir_y < 0)
		{
			tree->ray.tex_x = (int)(tree->ray.wall_x
					* (double)(tree->texture.s_tex_w));
			tree->ray.tex_x = tree->texture.s_tex_w - tree->ray.tex_x - 1;
		}
		else
			tree->ray.tex_x = (int)(tree->ray.wall_x
					* (double)(tree->texture.n_tex_w));
	}
}
