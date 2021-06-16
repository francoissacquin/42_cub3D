/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trgb_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsacquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 17:12:31 by fsacquin          #+#    #+#             */
/*   Updated: 2021/03/11 17:12:33 by fsacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	convert_trgb_into_single_int(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_single_color_value(int trgb, char c)
{
	if (c == 'T' || c == 't')
		return (trgb & (0xFF << 24));
	else if (c == 'R' || c == 'r')
		return (trgb & (0xFF << 16));
	else if (c == 'G' || c == 'g')
		return (trgb & (0xFF << 8));
	else if (c == 'B' || c == 'b')
		return (trgb & 0xFF);
	else
	{
		printf("Error\ninvalid color char|expected 'TRGBtrgb|result %c \n", c);
		return (0);
	}
}

int	add_shade(double s_factor, int trgb)
{
	int		new_r;
	int		new_g;
	int		new_b;

	if (s_factor < 0 || s_factor > 1)
	{
		printf("Error\ninvalid shade factor|Expected 0 to 1|result : %f \n",
			s_factor);
		return (trgb);
	}
	new_r = get_single_color_value(trgb, 'r') * (1 - s_factor);
	new_g = get_single_color_value(trgb, 'g') * (1 - s_factor);
	new_b = get_single_color_value(trgb, 'b') * (1 - s_factor);
	return (convert_trgb_into_single_int(trgb & (0xFF << 24),
			new_r, new_g, new_b));
}

int	reverse_color(int trgb)
{
	int		new_r;
	int		new_g;
	int		new_b;

	new_r = 255 - get_single_color_value(trgb, 'r');
	new_g = 255 - get_single_color_value(trgb, 'g');
	new_b = 255 - get_single_color_value(trgb, 'b');
	return (convert_trgb_into_single_int(trgb & (0xFF << 24),
			new_r, new_g, new_b));
}
