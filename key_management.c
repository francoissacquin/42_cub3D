/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsacquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:32:18 by fsacquin          #+#    #+#             */
/*   Updated: 2021/06/03 16:32:20 by fsacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	key_hook(int keycode, t_tree *tree)
{
	if (keycode == 65307)
		ft_close(tree);
	if (keycode == 65361)
		tree->vars.rot_right = 1;
	if (keycode == 97)
		tree->vars.strafe_right = 1;
	if (keycode == 65362 || keycode == 119)
		tree->vars.forward = 1;
	if (keycode == 65363)
		tree->vars.rot_left = 1;
	if (keycode == 100)
		tree->vars.strafe_left = 1;
	if (keycode == 65364 || keycode == 115)
		tree->vars.back = 1;
	ft_sprint(keycode, tree);
	screen_manager(tree);
	return (0);
}

int	key_release_hook(int keycode, t_tree *tree)
{
	if (keycode == 65361 && tree->vars.rot_right == 1)
		tree->vars.rot_right = 0;
	if (keycode == 97 && tree->vars.strafe_right == 1)
		tree->vars.strafe_right = 0;
	if ((keycode == 65362 || keycode == 119) && tree->vars.forward == 1)
		tree->vars.forward = 0;
	if (keycode == 65363 && tree->vars.rot_left == 1)
		tree->vars.rot_left = 0;
	if (keycode == 100 && tree->vars.strafe_left == 1)
		tree->vars.strafe_left = 0;
	if ((keycode == 65364 || keycode == 115) && tree->vars.back == 1)
		tree->vars.back = 0;
	ft_sprint(keycode, tree);
	screen_manager(tree);
	return (0);
}

void	ft_sprint(int keycode, t_tree *tree)
{
	if (keycode == 65505)
	{
		if (tree->image.sp == 0.1)
			tree->image.sp = 0.2;
		else
			tree->image.sp = 0.1;
	}
	ft_translate_vector(tree);
}

void	ft_translate_vector(t_tree *tree)
{
	if (tree->vars.rot_right == 1)
		right_rotate(tree);
	if (tree->vars.strafe_right == 1)
		strafe_right(tree);
	if (tree->vars.forward == 1)
		go_forward(tree);
	if (tree->vars.rot_left == 1)
		left_rotate(tree);
	if (tree->vars.strafe_left == 1)
		strafe_left(tree);
	if (tree->vars.back == 1)
		go_backward(tree);
}
