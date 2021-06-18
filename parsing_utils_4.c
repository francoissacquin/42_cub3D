/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsacquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 16:27:57 by fsacquin          #+#    #+#             */
/*   Updated: 2021/06/18 16:27:59 by fsacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	conveyor_belt_error(char **res_split, char *str, t_tree *tree)
{
	if (ft_strrchr("NSEW", res_split[0][0]) && ft_strlen_array(res_split) != 2)
		error_central_parsing(2, res_split, str, tree);
	else if (res_split[0][0] == 'R' && ft_strlen_array(res_split) != 3)
		error_central_parsing(2, res_split, str, tree);
	else if (res_split[0] != NULL)
		error_central_parsing(12, res_split, str, tree);
}

int		ft_strcmp(char *str1, char *str2)
{
	int		i;

	i = 0;
	while (str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return (1);
		i++;
	}
	if (str1[i] == str2[i])
		return (0);
	return (1);
}
