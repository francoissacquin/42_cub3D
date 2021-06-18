/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_central.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsacquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:05:05 by fsacquin          #+#    #+#             */
/*   Updated: 2021/04/15 16:58:20 by fsacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3D.h"

void	error_central_general(int index)
{
	if (index == 1)
		printf("Error\nwrong number of argument files given with a.out\n");
	else if (index == 2)
		printf("Error\nconfiguration does not end with .cub\n");
	else if (index == 3)
		printf("Error\n in open() of config.cub\n");
	exit(EXIT_SUCCESS);
}

void	error_central_parsing(int index, char **array,
		char *str, t_tree *tree)
{
	char	*s;

	s = 0;
	error_message_parsing(index);
	free(str);
	array = send_help((char const **)array, ft_strlen_array(array));
	while ((get_next_line(tree->parsing.fd, &s)) > 0)
	{
		free(s);
		s = 0;
	}
	free(s);
	s = 0;
	close(tree->parsing.fd);
	free_struc_texture_paths(tree);
	exit(EXIT_SUCCESS);
}

void	error_central_labyrinth_parsing(int index, char *str, t_tree *tree)
{
	error_message_labyrinth_parsing(index, tree);
	if (str != 0)
		free(str);
	if (tree->parsing.fd != 0)
	{
		while ((get_next_line(tree->parsing.fd, &str)) > 0)
		{
			free(str);
			str = 0;
		}
	}
	if (str != 0)
		free(str);
	free_struc_texture_paths(tree);
	if (tree->parsing.fd != 0)
		close(tree->parsing.fd);
	exit(EXIT_SUCCESS);
}

void	error_central_verify_labyrinth(int index, t_tree *tree)
{
	char	*str;

	str = 0;
	error_message_verify_labyrinth(index);
	if (tree->parsing.fd != 0)
	{
		while ((get_next_line(tree->parsing.fd, &str)) > 0)
		{
			free(str);
			str = 0;
		}
		free(str);
		str = 0;
	}
	free_struc_texture_paths(tree);
	free_struc_labyrinth(tree);
	exit(EXIT_SUCCESS);
}

void	error_central_tex(int index, t_tree *tree)
{
	error_message_tex(index);
	if (!(tree->texture.img_NO == 0))
		mlx_destroy_image(tree->vars.mlx, tree->texture.img_NO);
	if (!(tree->texture.img_SO == 0))
		mlx_destroy_image(tree->vars.mlx, tree->texture.img_SO);
	if (!(tree->texture.img_EA == 0))
		mlx_destroy_image(tree->vars.mlx, tree->texture.img_EA);
	if (!(tree->texture.img_WE == 0))
		mlx_destroy_image(tree->vars.mlx, tree->texture.img_WE);
	if (tree->image.img != 0)
		mlx_destroy_image(tree->vars.mlx, tree->vars.mlx);
	mlx_destroy_display(tree->vars.mlx);
	free(tree->vars.mlx);
	free_struc_texture_paths(tree);
	free_struc_labyrinth(tree);
	free(tree->parsing.file_path);
	exit(EXIT_SUCCESS);
}
