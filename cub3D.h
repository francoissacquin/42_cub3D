/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsacquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 17:13:01 by fsacquin          #+#    #+#             */
/*   Updated: 2021/06/07 16:27:31 by fsacquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include "./mlx_linux/mlx.h"

# define MLX_SYNC_IMAGE_WRITABLE		1
# define MLX_SYNC_WIN_FLUSH_CMD			2
# define MLX_SYNC_WIN_CMD_COMPLETED		3

typedef struct s_parsing_results
{
	char		*file_path;
	int			res_x;
	int			res_y;
	char		*n_tex_path;
	char		*s_tex_path;
	char		*e_tex_path;
	char		*w_tex_path;
	int			floor_color;
	int			ceiling_color;
	char		**lab;
	int			starting_x;
	int			starting_y;
	char		start_dir;
	int			par_res;
	int			fd;
}				t_pars_res;

typedef struct s_bool_switch
{
	int			NO;
	int			SO;
	int			EA;
	int			WE;
	int			C;
	int			F;
}				t_bool_switch;

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	double		play_x;
	double		play_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		sp;
}				t_data;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	int			x;
	int			y;
	int			rot_right;
	int			rot_left;
	int			strafe_right;
	int			strafe_left;
	int			forward;
	int			back;
}				t_vars;

typedef struct s_texture
{
	void		*img_NO;
	void		*img_WE;
	void		*img_EA;
	void		*img_SO;
	int			*tex_NO;
	int			*tex_SO;
	int			*tex_EA;
	int			*tex_WE;
	int			n_tex_h;
	int			n_tex_w;
	int			s_tex_h;
	int			s_tex_w;
	int			w_tex_h;
	int			w_tex_w;
	int			e_tex_h;
	int			e_tex_w;
	int			count;
}				t_tex;

typedef struct s_ray
{
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	double	wall_x;
	int		side;
	int		step_x;
	int		step_y;
	int		line_height;
	int		draw_start;
	int		draw_end;
	char	tex_num;
	int		tex_x;
	int		tex_y;
	int		color;
	double	step;
	double	tex_pos;
}			t_ray;

typedef struct s_tree
{
	t_tex			texture;
	t_pars_res		parsing;
	t_data			image;
	t_ray			ray;
	t_vars			vars;
	t_bool_switch	swit;
}			t_tree;

//general utils functions :
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	verify_file(int arg_num, char **arg, t_tree *tree);
char	*ft_strnstr(const char *str, const char *to_find, size_t length);
void	init_struc(t_tree *tree);
void	init_vars(t_tree *tree);
void	ft_img_init(t_tree *tree);
void	ft_init_plane(t_tree *tree);
void	fix_resolution(t_tree *tree);
void	extract_tex(void **img, int **xpm, char *path, t_tree *tree);
void	conveyor_tex(t_tree *tree);
void	assign_tex_dimensions(int width, int height, t_tree *tree);
void	free_struc_texture_paths(t_tree *tree);
void	free_struc_labyrinth(t_tree *tree);

//parsing functions for config.cub file :
void	input_parsing(t_tree *tree);
void	check_conveyor_belt(char **str, int lab_start_line, t_tree *tree);
void	conveyor_belt_error(char **res_split, char *str, t_tree *tree);
void	check_cf_color(char **res_split, char *str, t_tree *tree);
void	check_cf_color_plus(char **res_split, char *str, t_tree *tree);
void	cf_switch(char c, t_tree *tree);
void	check_resolution(char **res_split, char *str, t_tree *tree);
void	check_texture(char **res_split, char *str, t_tree *tree);
void	assign_texture(char **res_split, char c, char *str, t_tree *tree);
void	verify_texture_path(t_tree *tree, char **res_split, char *error,
			char *str);
char	texture_switch(char **res_split, t_tree *tree);
void	clear_parsing(char *str, t_tree *tree);

//color managing :
int		convert_trgb_into_single_int(int t, int r, int g, int b);
int		get_single_color_value(int trgb, char c);
int		add_shade(double s_factor, int trgb);
int		base_count(char *base, char c);

//parsing of the labyrinth :
void	lab_parsing_main(char *str, int lab_start_line, t_tree *tree);
void	lab_parsing_plus(char *str, int *biggest_len, int *left_shift,
			t_tree *tree);
void	assign_labyrinth(int *tab, t_tree *tree);
void	skip_lines(int start_line, int fd);
void	assign_lab_lines(int line, int line_len, int left_shift, t_tree *tree);
int		first_wall(char *str, int c);
int		last_wall(char *str, int c);
size_t	ft_strlen_array(char **array);
void	verify_labyrinth(int line_len, int line, t_tree *tree);
void	verify_lab_line(int x, int *starting_pos_count, int *tab, t_tree *tree);
int		is_boundary_wall_alone(int x, int y, int *tab, t_tree *tree);
int		n_wall_check(int y, int len, t_tree *tree);
int		s_wall_check(int y, int len, int line, t_tree *tree);
int		is_char_not_inside_walls(int x, int y, t_tree *tree);
void	verify_argument(t_tree *tree);

//flooding functions :
void	init_floodfill(t_tree *tree);
void	floodfill(int x, int y, int newnum, t_tree *tree);
int		get_pixel(int x, int y, t_tree *tree);
void	putpixel(int x, int y, int newnum, t_tree *tree);
void	check_post_floodfill(t_tree *tree);
void	undo_floodfill(int x, int y, int newnum, t_tree *tree);

// get_next_line functions :
int		get_next_line(int fd, char **line);
char	*ft_strdup(const char *str);
char	*ft_strjoin(const char *str1, const char *str2);
char	*ft_strrchr(const char *str, int c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
int		ft_atoi(const char *str);

// ft_split :
char	**ft_split(char const *s, char c);
char	**send_help(char const **split, int abs);

// screen manager and friends :
int		screen_manager(t_tree *tree);
int		screen_manager_2(t_tree *tree);

// minimap bonus :
/*
void	dividing_walls(t_tree *tree);
void	coloring_lab_cubes(int lab_x, int lab_y, int lines,
			int lin_len, t_tree *tree);
void	ft_draw_line(int x, int draw_start, int draw_end,
			int color, t_tree *tree);
*/

// key events and hooks :
int		key_hook(int keycode, t_tree *tree);
int		key_release_hook(int keycode, t_tree *tree);
int		ft_close(t_tree *tree);
void	ft_sprint(int keycode, t_tree *tree);
void	ft_translate_vector(t_tree *tree);

// keys, strafes and movements
void	right_rotate(t_tree *tree);
void	left_rotate(t_tree *tree);
void	strafe_right(t_tree *tree);
void	strafe_left(t_tree *tree);
void	go_forward(t_tree *tree);
void	go_backward(t_tree *tree);

// raycasting and god forbid what other horror you find in there :
void	raycasting(t_tree *tree);
void	init_camera_plane(int x, t_tree *tree);
void	calc_delta_dist(t_tree *tree);
void	calc_side_dist(t_tree *tree);
void	ray_until_wall(t_tree *tree);
void	draw_calc(t_tree *tree);
void	tex_select(t_tree *tree);
void	tex_x_calc(t_tree *tree);
void	tex_step_calc(t_tree *tree);
int		draw_ceiling(int x, int y, t_tree *tree);
int		draw_tex(int x, int y, t_tree *tree);
int		draw_floor(int x, int y, t_tree *tree);

//gestion d'erreurs :
void	error_central_general(int index);
void	error_message_parsing(int index);
void	error_central_parsing(int index, char **array, char *str, t_tree *tree);
void	error_central_labyrinth_parsing(int index, char *str, t_tree *tree);
void	error_message_labyrinth_parsing(int index, t_tree *tree);
void	error_central_verify_labyrinth(int index, t_tree *tree);
void	error_message_verify_labyrinth(int index);
void	error_central_tex(int index, t_tree *tree);
void	error_message_tex(int index);

#endif
