/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsacquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:40:25 by fsacquin          #+#    #+#             */
/*   Updated: 2021/06/06 15:33:04 by fsacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	n_wall_check(int y, int len, t_tree *tree)
{
	if (y == 0)
	{
		if (tree->parsing.lab[0][1] != '1' && tree->parsing.lab[1][0] != '1')
			return (1);
	}
	else if (y == len - 1)
	{
		if (tree->parsing.lab[0][len - 2] != '1'
				&& tree->parsing.lab[1][len - 1] != '1')
			return (1);
	}
	else
	{
		if (tree->parsing.lab[1][y] != '1' && tree->parsing.lab[0][y - 1]
				!= '1' && tree->parsing.lab[0][y + 1] != '1')
			return (1);
	}
	return (0);
}

int	s_wall_check(int y, int len, int line, t_tree *tree)
{
	if (y == 0)
	{
		if (tree->parsing.lab[line - 2][0] != '1'
				&& tree->parsing.lab[line - 1][1] != '1')
			return (1);
	}
	else if (y == len - 1)
	{
		if (tree->parsing.lab[line - 2][len - 1] != '1' &&
				tree->parsing.lab[line - 1][len - 2] != '1')
			return (1);
	}
	else
		if (tree->parsing.lab[line - 2][y] != '1'
				&& tree->parsing.lab[line - 1][y - 1]
				!= '1' && tree->parsing.lab[line - 1][y + 1] != '1')
			return (1);
	return (0);
}
