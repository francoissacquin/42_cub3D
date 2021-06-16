/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsacquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 11:45:28 by fsacquin          #+#    #+#             */
/*   Updated: 2021/04/18 17:09:45 by fsacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	extract_tex(void **img, int **xpm, char *path, t_tree *tree)
{
	int		tab[5];

	*img = mlx_xpm_file_to_image(tree->vars.mlx, path, &tab[0], &tab[1]);
	if (*img == NULL)
		error_central_tex(6, tree);
	*xpm = (int *)mlx_get_data_addr(*img, &tab[2], &tab[3], &tab[4]);
	if (*xpm == NULL)
		error_central_tex(8, tree);
	assign_tex_dimensions(tab[0], tab[1], tree);
}

void	assign_tex_dimensions(int width, int height, t_tree *tree)
{
	if (tree->texture.count == 0)
	{
		tree->texture.n_tex_w = width;
		tree->texture.n_tex_h = height;
	}
	if (tree->texture.count == 1)
	{
		tree->texture.s_tex_w = width;
		tree->texture.s_tex_h = height;
	}
	if (tree->texture.count == 2)
	{
		tree->texture.e_tex_w = width;
		tree->texture.e_tex_h = height;
	}
	if (tree->texture.count == 3)
	{
		tree->texture.w_tex_w = width;
		tree->texture.w_tex_h = height;
	}
}

void	conveyor_tex(t_tree *tree)
{
	tree->texture.img_NO = 0;
	tree->texture.img_SO = 0;
	tree->texture.img_EA = 0;
	tree->texture.img_WE = 0;
	tree->texture.tex_NO = 0;
	tree->texture.tex_SO = 0;
	tree->texture.tex_EA = 0;
	tree->texture.tex_WE = 0;
	tree->texture.count = 0;
	extract_tex(&tree->texture.img_NO, &tree->texture.tex_NO,
		tree->parsing.n_tex_path, tree);
	tree->texture.count = 1;
	extract_tex(&tree->texture.img_SO, &tree->texture.tex_SO,
		tree->parsing.s_tex_path, tree);
	tree->texture.count = 2;
	extract_tex(&tree->texture.img_EA, &tree->texture.tex_EA,
		tree->parsing.e_tex_path, tree);
	tree->texture.count = 3;
	extract_tex(&tree->texture.img_WE, &tree->texture.tex_WE,
		tree->parsing.w_tex_path, tree);
}

void	fix_resolution(t_tree *tree)
{
	if (tree->parsing.res_x == 0 || tree->parsing.res_y == 0)
	{
		tree->parsing.res_x = 960;
		tree->parsing.res_y = 540;
	}
	if (tree->parsing.res_x > 1920 || tree->parsing.res_y > 1080)
	{
		printf("Error\nres_x superior to 1920 or res_y superior to 1080, resolution was set to 960 540\n");
		tree->parsing.res_x = 960;
		tree->parsing.res_y = 540;
	}
}

int	main(int argc, char **argv)
{
	t_tree	tree;

	tree.vars.x = 0;
	tree.vars.y = 0;
	tree.image.img = 0;
	verify_file(argc, argv, &tree);
	init_struc(&tree);
	input_parsing(&tree);
	verify_argument(&tree);
	fix_resolution(&tree);
	ft_img_init(&tree);
	tree.vars.mlx = mlx_init();
	conveyor_tex(&tree);
	tree.vars.win = mlx_new_window(tree.vars.mlx, tree.parsing.res_x,
			tree.parsing.res_y, "cub3D");
	init_vars(&tree);
	printf("%ls\n", tree.texture.tex_EA);
	screen_manager(&tree);
	mlx_hook(tree.vars.win, 2, 1L << 0, &key_hook, &tree);
	mlx_hook(tree.vars.win, 3, 1L << 1, &key_release_hook, &tree);
	mlx_hook(tree.vars.win, 33, 0L, ft_close, &tree);
	mlx_loop_hook(tree.vars.mlx, &screen_manager_2, &tree);
	mlx_do_sync(tree.vars.mlx);
	mlx_loop(tree.vars.mlx);
}
