/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 17:22:36 by pablo             #+#    #+#             */
/*   Updated: 2020/01/09 18:26:23 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include "mlx.h"
# include "../srcs/libft/libft.h"
# include <math.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct	s_map
{
	int				width;
	int				height;
	int				x_max;
	int				y_max;
	int				**tab_map;
}				t_map;

typedef struct	s_ray
{
	double			camerax;
	double			raydirx;
	double			raydiry;
	int				mapx;
	int				mapy;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			perpwalldist;
	double			wallhit_x;
	double			wallhit_y;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				lineheight;
	int				drawstart;
	int				drawend;
	int				color;
}				t_ray;

typedef struct	s_color
{
	int				empty;
	int				r;
	int				g;
	int				b;
}				t_color;

typedef struct	s_image
{
	void			*id;
	int				*image;
	int				data;
	int				w;
	int				h;
	int				endian;
	int				size_line;
}				t_image;

typedef struct	s_text
{
	char			*path;
	void			*id;
	int				*image;
	int				data;
	int				w;
	int				h;
	int				endian;
	int				size_line;
}				t_text;

typedef struct	s_keys
{
	int				key_w;
	int				key_a;
	int				key_s;
	int				key_d;
	int				key_iz;
	int				key_dir;
}				t_keys;

typedef struct	s_textures
{
	t_text			north_text;
	t_text			south_text;
	t_text			east_text;
	t_text			weast_text;
	t_text			sprite;
	t_color			floor_color;
	t_color			ceilling_color;
}				t_textures;

typedef struct	s_valid
{
	int				resolution;
	int				n_text;
	int				s_text;
	int				e_text;
	int				w_text;
	int				sp_text;
	int				floor;
	int				ceilling;
	int				content_map;
	int				first_map;
	int				last_map;
	int				num_sprites;
}				t_valid;

typedef struct	s_sprite
{
	double			posx;
	double			posy;
}				t_sprite;

typedef struct	s_rays
{
	int				*spriteorder;
	double			*spritedistance;
	double			spritex;
	double			spritey;
	double			invdet;
	double			transformx;
	double			transformy;
	int				spritescreenx;
	int				vmovescreen;
	int				spriteheight;
	int				drawstarty;
	int				drawendy;
	int				spritewidth;
	int				drawstartx;
	int				drawendx;
	int				print_y;
}				t_rays;

typedef struct	s_data
{
	void			*mlx_ptr;
	void			*mlx_win;
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	int				num_sprites;
	double			*depth;
	t_ray			ray;
	t_rays			ray_sprite;
	t_map			map;
	t_textures		textur;
	t_image			img;
	t_keys			keys;
	t_sprite		*sprite;
}				t_data;

# define UDIV				1
# define VDIV				1
# define VMOVE				0.0
# define KEY_ESC			53
# define KEY_A				0
# define KEY_W				13
# define KEY_S				1
# define KEY_D				2
# define KEY_ARROW_LEFT		123
# define KEY_ARROW_UP		126
# define KEY_ARROW_RIGHT	124
# define KEY_ARROW_DOWN		125
# define SCREENSHOT_PATH	"screenshot.bmp"
# define BYTES_PER_PIXEL	4
# define INFO_HEADER_SIZE	40
# define FILE_HEADER_SIZE	14

int				init_render(t_data *player);
void			bmp_check(t_data *player, char *argv[]);
double			ft_pow(double num);
void			render_sprite(t_data *player);
void			free_all(t_data *player);
void			free_path_textures(t_data *player, int control);
void			parse_map(t_data *player, char *line);
int				isvalid(char *argv[]);
int				check_map(t_valid *check);
int				check_resolution(char *line, t_valid *check);
int				check_textures(char *line, t_valid *check);
int				check_sprite(char *line, t_valid *check);
int				check_color(char *line, t_valid *check);
void			ft_exit(int control);
int				create_bmp(t_data *player);
t_text			get_texture(t_data *player);
int				rotate_player(t_data *player, double rotspeed);
int				up_down_player(t_data *player, double movespeed, double dirx,
				double diry);
int				left_rigth_player(t_data *player, double movespeed,
				double planex, double planey);
int				get_next_line(int fd, char **line);
void			get_resolution(t_data *player, char *line);
int				check_map_bg(char *line);
void			create_map(char *line, int x, t_data *player, int *sp_x);
void			isfirst_or_last_line(char *line, t_data *player);
int				count_line(char *line);
void			charge_textures_main(t_data *player);
void			get_coordenate(t_data *player, char c);
void			get_sprite(t_data *player, char *line);
void			get_colors(char *line, t_color *color, char param);
int				get_map_numbers(int fd_open, t_data *player);
void			get_map(t_data *player, char *line);
void			get_textures(t_data *player, char *line);
t_data			*init_player(char *argv[], int argc, int num_sprites);
void			render(t_data *player);
int				get_color_bmp(unsigned char *image, int x, int y,
				t_data *player);
void			print_column(t_data *player, int end, int coord,
				t_text texture);
void			print_sprite(t_data *player);
int				get_pixel(t_text *image, double y, double x);
int				get_distance_sprites(t_data *player);
int				hook_key_close(t_data *player);
int				hook_key_press(int key, t_data *player);
int				hook_key_release(int key, t_data *player);
int				exit_program(t_data *player);
#endif
