/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsacquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 17:12:18 by fsacquin          #+#    #+#             */
/*   Updated: 2021/04/21 19:13:15 by fsacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	input_parsing(t_tree *tree)
{
	int		lab_start_line;
	char	*str;

	str = 0;
	lab_start_line = 0;
	tree->parsing.fd = open((char const *)tree->parsing.file_path, O_RDONLY);
	if (tree->parsing.fd == -1)
	{
		free(tree->parsing.file_path);
		error_central_general(3);
	}
	while ((get_next_line(tree->parsing.fd, &str)) > 0)
	{
		if (str[0] != '\0')
			check_conveyor_belt(&str, lab_start_line, tree);
		if (str == 0)
			break;
		free(str);
		str = 0;
		lab_start_line++;
	}
	if (tree->parsing.lab == 0)
		error_central_labyrinth_parsing(5, str, tree);
	free(str);
	close(tree->parsing.fd);
	tree->parsing.fd = 0;
	init_floodfill(tree);
}

void	check_conveyor_belt(char **str, int lab_start_line, t_tree *tree)
{
	char	**res_split;

	res_split = ft_split(*str, ' ');
	if (ft_strrchr("NSEW", res_split[0][0]))
	{
		if (ft_strlen_array(res_split) != 2)
			error_central_parsing(2, res_split, *str, tree);
		else
			check_texture(res_split, *str, tree);
	}
	else if (res_split[0][0] == 'R' )
	{
		if (ft_strlen_array(res_split) != 3)
			error_central_parsing(2, res_split, *str, tree);
		else
			check_resolution(res_split, *str, tree);
	}
	else if ((res_split[0][0] == 'C' && tree->swit.C == 0) || (res_split[0][0] == 'F' && tree->swit.F == 0))
		check_cf_color(res_split, *str, tree);
	else if (ft_strrchr(res_split[0], '1'))
	{
		res_split = send_help((char const **)res_split,
			ft_strlen_array(res_split));
		lab_parsing_main(*str, lab_start_line, tree);
		*str = NULL;
	}
	else if (res_split[0] != NULL)
		error_central_parsing(12, res_split, *str, tree);
	if (res_split != NULL)
		res_split = send_help((char const **)res_split,
			ft_strlen_array(res_split));
}

void	check_cf_color(char **res_split, char *str, t_tree *tree)
{
	int		r;
	int		g;
	int		b;
	char	**r_g_b;

	check_cf_color_plus(res_split, str, tree);
	r_g_b = ft_split((char const *)res_split[1], ',');
	if (ft_strlen_array(r_g_b) != 3)
	{
		r_g_b = send_help((char const **)r_g_b, ft_strlen_array(r_g_b));
		error_central_parsing(3, res_split, str, tree);
	}
	r = ft_atoi((char *)r_g_b[0]);
	g = ft_atoi((char *)r_g_b[1]);
	b = ft_atoi((char *)r_g_b[2]);
	r_g_b = send_help((char const **)r_g_b, ft_strlen_array(r_g_b));
	if (r > 255 || r < 0 || g > 255 || g < 0 || b > 255 || b < 0)
		error_central_parsing(4, res_split, str, tree);
	if (res_split[0][0] == 'C')
		tree->parsing.ceiling_color = convert_trgb_into_single_int(0, r, g, b);
	else if (res_split[0][0] == 'F')
		tree->parsing.floor_color = convert_trgb_into_single_int(0, r, g, b);
	cf_switch(res_split[0][0], tree);
}

void	check_resolution(char **res_split, char *str, t_tree *tree)
{
	int		i;
	int		len;

	len = ft_strlen((const char *)res_split[1]);
	i = 0;
	while (i < len)
	{
		if (ft_strrchr("0123456789", res_split[1][i]))
			i++;
		else
			error_central_parsing(5, res_split, str, tree);
	}
	tree->parsing.res_x = ft_atoi((const char *)res_split[1]);
	len = ft_strlen((const char *)res_split[2]);
	i = 0;
	while (i < len)
	{
		if (ft_strrchr("0123456789", res_split[2][i]))
			i++;
		else
			error_central_parsing(6, res_split, str, tree);
	}
	tree->parsing.res_y = ft_atoi((const char *)res_split[2]);
	if (tree->parsing.res_x < 1 || tree->parsing.res_y < 1)
		error_central_parsing(9, res_split, str, tree);
}

void	check_texture(char **res_split, char *str, t_tree *tree)
{
	char	cardinal;


	cardinal = texture_switch(res_split, tree);
	if (res_split[1][0] == '.' && ft_strrchr("NSEW", cardinal))
		assign_texture(res_split, cardinal, str, tree);
	else
		error_central_parsing(7, res_split, str, tree);
}
