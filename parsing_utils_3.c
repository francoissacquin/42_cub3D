/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsacquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 16:13:51 by fsacquin          #+#    #+#             */
/*   Updated: 2021/06/18 16:13:58 by fsacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_cf_color_plus(char **res_split, char *str, t_tree *tree)
{
	int	i;
	int	count_comma;

	if (ft_strlen_array(res_split) != 2)
		error_central_parsing(2, res_split, str, tree);
	i = 0;
	count_comma = 0;
	while (res_split[1][i])
	{
		if (res_split[1][i] < 58 && res_split[1][i] > 47)
			i++;
		else if (res_split[1][i] == ',')
		{
			count_comma++;
			i++;
		}
		else
			error_central_parsing(11, res_split, str, tree);
	}
	if (count_comma != 2)
		error_central_parsing(11, res_split, str, tree);
}

char	texture_switch(char **res_split, t_tree *tree)
{
	char	cardinal;

	cardinal = 'X';
	if (ft_strcmp(res_split[0], "NO") == 0 && tree->swit.NO == 0)
	{
		cardinal = res_split[0][0];
		tree->swit.NO = 1;
	}
	else if (ft_strcmp(res_split[0], "SO") == 0 && tree->swit.SO == 0)
	{
		cardinal = res_split[0][0];
		tree->swit.SO = 1;
	}
	else if (ft_strcmp(res_split[0], "WE") == 0 && tree->swit.WE == 0)
	{
		cardinal = res_split[0][0];
		tree->swit.WE = 1;
	}
	else if (ft_strcmp(res_split[0], "EA") == 0 && tree->swit.EA == 0)
	{
		cardinal = res_split[0][0];
		tree->swit.EA = 1;
	}
	return (cardinal);
}

void	cf_switch(char c, t_tree *tree)
{
	if (c == 'C')
		tree->swit.C = 1;
	if (c == 'F')
		tree->swit.F = 1;
}

void	verify_argument(t_tree *tree)
{
	if (tree->swit.NO == 0)
		error_central_verify_labyrinth(6, tree);
	if (tree->swit.SO == 0)
		error_central_verify_labyrinth(6, tree);
	if (tree->swit.EA == 0)
		error_central_verify_labyrinth(6, tree);
	if (tree->swit.WE == 0)
		error_central_verify_labyrinth(6, tree);
	if (tree->swit.C == 0 || tree->swit.C == 0)
		error_central_verify_labyrinth(6, tree);
}

void	clear_parsing(char *str, t_tree *tree)
{
	free(str);
	close(tree->parsing.fd);
	tree->parsing.fd = 0;
}
