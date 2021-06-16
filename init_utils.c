/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsacquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 10:58:28 by fsacquin          #+#    #+#             */
/*   Updated: 2021/03/12 10:58:33 by fsacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	verify_file(int arg_num, char **arg, t_tree *tree)
{
	int		i;
	int		j;

	i = 0;
	if (arg_num != 2)
		error_central_general(1);
	while (arg[1][i])
		i++;
	if (!(&arg[1][i - 4] == ft_strnstr((char const *)arg[1], ".cub", i)))
		error_central_general(2);
	tree->parsing.file_path = (char *)malloc(sizeof(char) * (i + 3));
	tree->parsing.file_path[0] = '.';
	tree->parsing.file_path[1] = '/';
	i = 0;
	j = 2;
	while (arg[1][i])
		tree->parsing.file_path[j++] = arg[1][i++];
	tree->parsing.file_path[j] = '\0';
}

void	init_struc(t_tree *tree)
{
	tree->parsing.res_x = 0;
	tree->parsing.res_y = 0;
	tree->parsing.floor_color = 0;
	tree->parsing.ceiling_color = 0;
	tree->parsing.n_tex_path = 0;
	tree->parsing.s_tex_path = 0;
	tree->parsing.w_tex_path = 0;
	tree->parsing.e_tex_path = 0;
	tree->parsing.lab = 0;
	tree->swit.NO = 0;
	tree->swit.SO = 0;
	tree->swit.EA = 0;
	tree->swit.WE = 0;
	tree->swit.C = 0;
	tree->swit.F = 0;
}

void	init_vars(t_tree *tree)
{
	tree->vars.rot_right = 0;
	tree->vars.rot_left = 0;
	tree->vars.strafe_right = 0;
	tree->vars.strafe_left = 0;
	tree->vars.forward = 0;
	tree->vars.back = 0;
}

void	ft_img_init(t_tree *tree)
{
	tree->image.play_x = tree->parsing.starting_y + 0.5;
	tree->image.play_y = ft_strlen_array(tree->parsing.lab)
		- tree->parsing.starting_x - 0.5;
	if (tree->parsing.start_dir == 'N')
	{
		tree->image.dir_x = 0;
		tree->image.dir_y = 1;
	}
	else if (tree->parsing.start_dir == 'S')
	{
		tree->image.dir_x = 0;
		tree->image.dir_y = -1;
	}
	else if (tree->parsing.start_dir == 'W')
	{
		tree->image.dir_x = -1;
		tree->image.dir_y = 0;
	}
	else if (tree->parsing.start_dir == 'E')
	{
		tree->image.dir_x = 1;
		tree->image.dir_y = 0;
	}
	ft_init_plane(tree);
	tree->image.sp = 0.1;
}

void	ft_init_plane(t_tree *tree)
{
	if (tree->parsing.start_dir == 'N')
	{
		tree->image.plane_x = 0.66;
		tree->image.plane_y = 0;
	}
	else if (tree->parsing.start_dir == 'S')
	{
		tree->image.plane_x = -0.66;
		tree->image.plane_y = 0;
	}
	else if (tree->parsing.start_dir == 'W')
	{
		tree->image.plane_x = 0;
		tree->image.plane_y = 0.66;
	}
	else if (tree->parsing.start_dir == 'E')
	{
		tree->image.plane_x = 0;
		tree->image.plane_y = -0.66;
	}
}
