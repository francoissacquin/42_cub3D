/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsacquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:36:13 by fsacquin          #+#    #+#             */
/*   Updated: 2021/06/03 16:36:15 by fsacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_struc_texture_paths(t_tree *tree)
{
	if (tree->parsing.n_tex_path != 0)
	{
		free(tree->parsing.n_tex_path);
		tree->parsing.n_tex_path = 0;
	}
	if (tree->parsing.s_tex_path != 0)
	{
		free(tree->parsing.s_tex_path);
		tree->parsing.s_tex_path = 0;
	}
	if (tree->parsing.e_tex_path != 0)
	{
		free(tree->parsing.e_tex_path);
		tree->parsing.e_tex_path = 0;
	}
	if (tree->parsing.w_tex_path != 0)
	{
		free(tree->parsing.w_tex_path);
		tree->parsing.w_tex_path = 0;
	}
	if (tree->parsing.file_path != 0)
	{
		free(tree->parsing.file_path);
		tree->parsing.file_path = 0;
	}
}

void	free_struc_labyrinth(t_tree *tree)
{
	int		i;

	if (tree->parsing.lab != 0)
	{
		i = ft_strlen_array(tree->parsing.lab) + 1;
		tree->parsing.lab = send_help((char const **)tree->parsing.lab, i);
		tree->parsing.lab = 0;
	}
}

int	ft_close(t_tree *tree)
{
	if (tree->image.img != 0)
		mlx_destroy_image(tree->vars.mlx, tree->image.img);
	mlx_destroy_image(tree->vars.mlx, tree->texture.img_NO);
	mlx_destroy_image(tree->vars.mlx, tree->texture.img_SO);
	mlx_destroy_image(tree->vars.mlx, tree->texture.img_EA);
	mlx_destroy_image(tree->vars.mlx, tree->texture.img_WE);
	mlx_destroy_window(tree->vars.mlx, tree->vars.win);
	mlx_destroy_display(tree->vars.mlx);
	mlx_loop_end(&tree->vars);
	free(tree->vars.mlx);
	free_struc_labyrinth(tree);
	free_struc_texture_paths(tree);
	free(tree->parsing.file_path);
	exit(EXIT_SUCCESS);
	return (0);
}
