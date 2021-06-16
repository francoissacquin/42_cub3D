/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_movement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsacquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 15:35:59 by fsacquin          #+#    #+#             */
/*   Updated: 2021/06/03 15:36:01 by fsacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	right_rotate(t_tree *tree)
{
	double	old_dir_x;
	double	old_plane_x;

	tree->image.sp = tree->image.sp / 2;
	old_dir_x = tree->image.dir_x;
	tree->image.dir_x = tree->image.dir_x * cos(tree->image.sp)
		- tree->image.dir_y * sin(tree->image.sp);
	tree->image.dir_y = old_dir_x * sin(tree->image.sp) + tree->image.dir_y
		* cos(tree->image.sp);
	old_plane_x = tree->image.plane_x;
	tree->image.plane_x = tree->image.plane_x * cos(tree->image.sp)
		- tree->image.plane_y * sin(tree->image.sp);
	tree->image.plane_y = old_plane_x * sin(tree->image.sp)
		+ tree->image.plane_y * cos(tree->image.sp);
	tree->image.sp = tree->image.sp * 2;
}

void	left_rotate(t_tree *tree)
{
	double	old_dir_x;
	double	old_plane_x;

	tree->image.sp = tree->image.sp / 2;
	old_dir_x = tree->image.dir_x;
	tree->image.dir_x = tree->image.dir_x * cos(-tree->image.sp)
		- tree->image.dir_y * sin(-tree->image.sp);
	tree->image.dir_y = old_dir_x * sin(-tree->image.sp)
		+ tree->image.dir_y * cos(-tree->image.sp);
	old_plane_x = tree->image.plane_x;
	tree->image.plane_x = tree->image.plane_x * cos(-tree->image.sp)
		- tree->image.plane_y * sin(-tree->image.sp);
	tree->image.plane_y = old_plane_x * sin(-tree->image.sp)
		+ tree->image.plane_y * cos(-tree->image.sp);
	tree->image.sp = tree->image.sp * 2;
}

void	go_forward(t_tree *tree)
{
	int	line_len;
	int	vect_comp;
	int	vect_const;

	line_len = ft_strlen_array(tree->parsing.lab) - 1;
	vect_comp = (int)(tree->image.play_y + tree->image.dir_y
			* (tree->image.sp * 2));
	vect_const = (int)(tree->image.play_x);
	if (ft_strrchr("0NSEW", tree->parsing.lab[line_len - vect_comp]
			[vect_const]))
		tree->image.play_y += tree->image.dir_y * tree->image.sp;
	vect_comp = (int)(tree->image.play_x + tree->image.dir_x
			* (tree->image.sp * 2));
	vect_const = (int)(tree->image.play_y);
	if (ft_strrchr("0NSEW", tree->parsing.lab[line_len - vect_const]
			[vect_comp]))
		tree->image.play_x += tree->image.dir_x * tree->image.sp;
}

void	go_backward(t_tree *tree)
{
	int	line_len;
	int	vect_comp;
	int	vect_const;

	line_len = ft_strlen_array(tree->parsing.lab) - 1;
	vect_comp = (int)(tree->image.play_y - tree->image.dir_y
			* (tree->image.sp * 2));
	vect_const = (int)(tree->image.play_x);
	if (ft_strrchr("0NSEW", tree->parsing.lab[line_len - vect_comp]
			[vect_const]))
		tree->image.play_y -= tree->image.dir_y * tree->image.sp;
	vect_comp = (int)(tree->image.play_x - tree->image.dir_x
			* (tree->image.sp * 2));
	vect_const = (int)(tree->image.play_y);
	if (ft_strrchr("0NSEW", tree->parsing.lab[line_len - vect_const]
			[vect_comp]))
		tree->image.play_x -= tree->image.dir_x * tree->image.sp;
}
