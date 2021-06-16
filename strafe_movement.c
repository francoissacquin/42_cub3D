/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strafe_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsacquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:05:20 by fsacquin          #+#    #+#             */
/*   Updated: 2021/06/03 16:05:21 by fsacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	strafe_right(t_tree *tree)
{
	int	line_len;
	int	vect_comp;
	int	vect_const;

	line_len = ft_strlen_array(tree->parsing.lab) - 1;
	vect_comp = (int)(tree->image.play_y + tree->image.dir_x
			* (tree->image.sp * 2));
	vect_const = (int)(tree->image.play_x);
	if (ft_strrchr("0NSWE", tree->parsing.lab[line_len - vect_comp]
			[vect_const]))
		tree->image.play_y += tree->image.dir_x * tree->image.sp;
	vect_comp = (int)(tree->image.play_x + (-1 * tree->image.dir_y)
			* (tree->image.sp * 2));
	vect_const = (int)(tree->image.play_y);
	if (ft_strrchr("0NSWE", tree->parsing.lab[line_len - vect_const]
			[vect_comp]))
		tree->image.play_x += (-1 * tree->image.dir_y) * tree->image.sp;
}

void	strafe_left(t_tree *tree)
{
	int	line_len;
	int	vect_comp;
	int	vect_const;

	line_len = ft_strlen_array(tree->parsing.lab) - 1;
	vect_comp = (int)(tree->image.play_y + (-1 * tree->image.dir_x)
			* (tree->image.sp * 2));
	vect_const = (int)(tree->image.play_x);
	if (ft_strrchr("0NSEW", tree->parsing.lab[line_len - vect_comp]
			[vect_const]))
		tree->image.play_y += (-1 * tree->image.dir_x) * tree->image.sp;
	vect_comp = (int)(tree->image.play_x + tree->image.dir_y
			* (tree->image.sp * 2));
	vect_const = (int)(tree->image.play_y);
	if (ft_strrchr("0NSEW", tree->parsing.lab[line_len - vect_const]
			[vect_comp]))
		tree->image.play_x += tree->image.dir_y * tree->image.sp;
}
