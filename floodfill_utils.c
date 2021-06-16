/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsacquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 15:52:33 by fsacquin          #+#    #+#             */
/*   Updated: 2021/06/02 15:52:39 by fsacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_pixel(int x, int y, t_tree *tree)
{
	return (tree->parsing.lab[x][y] - 48);
}

void	putpixel(int x, int y, int newnum, t_tree *tree)
{
	tree->parsing.lab[x][y] = newnum + 48;
}
