/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 17:22:36 by pablo             #+#    #+#             */
/*   Updated: 2020/01/10 14:14:00 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include "mlx.h"
# include "../srcs/libft/libft.h"
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include <time.h>

typedef struct		s_map
{
	int			width;
	int			height;
	int			screen_height;
	int			x_max;
	int			y_max;
	int			**tab_map;
	int			sp_x;
	int			size_minimap;
}					t_map;

typedef struct		s_ray
{
	double		camerax;
	double		raydirx;
	double		raydiry;
	int			mapx;
	int			mapy;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	double		perpwalldist;
	double		wallhit_x;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			seeprite;
	int			lineheight;
	int			drawstart;
	int			drawend;
	int			color;
}					t_ray;

typedef struct		s_color
{
	int			empty;
	int			r;
	int			g;
	int			b;
}					t_color;

typedef struct		s_image
{
	void		*id;
	int			*image;
	int			data;
	int			w;
	int			h;
	int			endian;
	int			size_line;
}					t_image;

typedef struct		s_text
{
	char		*path;
	void		*id;
	int			*image;
	int			data;
	int			w;
	int			h;
	int			endian;
	int			size_line;
}					t_text;

typedef struct		s_keys
{
	int			key_w;
	int			key_a;
	int			key_s;
	int			key_d;
	int			key_iz;
	int			key_dir;
	int			key_space;
	int			x_begin;
	int			x_end;
	int			y_begin;
	int			y_end;
}					t_keys;

typedef struct		s_textures
{
	t_text		north_text;
	t_text		south_text;
	t_text		east_text;
	t_text		weast_text;
	t_text		layaout;
	t_text		gun;
	t_text		gunshot;
	t_text		*sprite;
	t_text		floor;
	t_text		ceilling;
	t_text		gameover;
}					t_textures;

typedef struct		s_valid
{
	int			resolution;
	int			n_text;
	int			s_text;
	int			e_text;
	int			w_text;
	int			sp_text;
	int			floor;
	int			ceilling;
	int			content_map;
	int			first_map;
	int			last_map;
	int			num_sprites;
}					t_valid;

typedef struct		s_sprite
{
	double		posx;
	double		posy;
	int			n_text;
	int			hp;
}					t_sprite;

typedef struct		s_rays
{
	int			*spriteorder;
	double		*spritedistance;
	double		spritex;
	double		spritey;
	double		invdet;
	double		transformx;
	double		transformy;
	int			spritescreenx;
	int			vmovescreen;
	int			spriteheight;
	int			drawstarty;
	int			drawendy;
	int			spritewidth;
	int			drawstartx;
	int			drawendx;
	int			print_y;
}					t_rays;

typedef struct		s_floorceil
{
	double		floorxwall;
	double		floorywall;
	double		distwall;
	double		distplayer;
	double		currentdist;
	double		weight;
	double		currentfloorx;
	double		currentfloory;
	int			floortex;
	int			floortexy;
}					t_floorceil;

typedef struct		s_printgun
{
	int			x_bgin;
	int			x_end;
	int			y_bgin;
	int			y_end;
	int			x;
	int			y;
	int			x_0;
	int			y_0;
	double		how_x;
	double		how_y;
	unsigned int color;

}					t_printgun;

typedef struct		s_printhp
{
	int		y;
	int		x;
	double	how_x;
	double	how_y;
	int		hpwidth;
	int		hp;
	int		hpheigth;
	int		how_xlf;
	int		how_ylf;
	int		resx;
	int		resy;
}					t_printhp;


typedef struct		s_data
{
	void		*mlx_ptr;
	void		*mlx_win;
	int			init_game;
	int			argc;
	char		*argv[2];
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	int			num_sprites;
	double		*depth;
	double		hp_max;
	double		hp_current;
	int			bullet_max;
	int			bullet_current;
	int			items_current;
	t_ray		ray;
	t_rays		ray_sprite;
	t_map		map;
	t_textures	textur;
	t_image		img;
	t_keys		keys;
	t_sprite	*sprite;
	t_floorceil	floorceilling;
	t_printgun	gun;
	t_printhp	hp;
}					t_data;

# define UDIV				1
# define VDIV				1
# define VMOVE				0.0
# define KEY_ESC			53
# define KEY_A				0
# define KEY_W				13
# define KEY_S				1
# define KEY_D				2
# define KEY_SPACE			49
# define KEY_ENTER			36
# define KEY_ARROW_LEFT		123
# define KEY_ARROW_UP		126
# define KEY_ARROW_RIGHT	124
# define KEY_ARROW_DOWN		125
# define SCREENSHOT_PATH	"screenshot.bmp"
# define BYTES_PER_PIXEL	4
# define FILE_HEADER_SIZE	14
# define INFO_HEADER_SIZE	40

void				free_game(t_data *player);
int					charge_textures(t_data *player, t_text *texture);
void				init_game(int argc, char *argv[]);
void				update_screen(t_data *player);
void				enemy_attack(t_data *player);
void				animate_sprite(t_data *player);
void				init_print_hp(t_data *player);
void				floorcasting(t_data *player, int coord);
void				control_life(t_data *player);
int					shot(t_data *player);
void				change_sprite(t_data *player, int posx, int posy);
void				delete_sprite(t_data *player, int posx, int posy);
int					create_color(int r, int g, int b);
void				print_gun(t_data *player);
void				get_crosshair(t_data *player);
void				print_crosshair(t_data *player);
void				print_hud(t_data *player);
int					init_render(t_data *player);
void				bmp_check(t_data *player, char *argv[]);
double				ft_pow(double num);
int					get_color_bmp(unsigned char *image, int x, int y,
					t_data *player);
void				render_sprite(t_data *player);
int					get_pixel(t_text *image, double y, double x);
void				free_all(t_data *player);
void				free_path_textures(t_data *player, int control);
void				parse_map(t_data *player, char *line);
int					isvalid(char *argv[]);
int					check_map(t_valid *check);
int					check_resolution(char *line, t_valid *check);
int					check_textures(char *line, t_valid *check);
int					check_sprite(char *line, t_valid *check, char letter);
int					check_color(char *line, t_valid *check);
void				ft_exit(int control);
void				free_all_bmp(t_data *player);
int					exit_program_bmp(t_data *player);
int					create_bmp(t_data *player);
void				control_bullets(t_data *player, double dir, int side);
void				control_items(t_data *player, double dir, int side);
void				control_hp(t_data *player, double dir, int side);
t_text				get_texture(t_data *player);
int					rotate_player(t_data *player, double rotspeed);
int					up_down_player(t_data *player, double movespeed,
					double dirx, double diry);
int					left_rigth_player(t_data *player, double movespeed,
					double planex, double planey);
int					get_next_line(int fd, char **line);
void				print_sprite(t_data *player, int i);
void				get_resolution(t_data *player, char *line);
int					check_map_bg(char *line);
void				create_map(char *line, int x, t_data *player);
void				isfirst_or_last_line(char *line, t_data *player);
int					count_line(char *line);
void				charge_textures_main(t_data *player);
void				get_coordenate(t_data *player, char c);
void				get_sprite(t_data *player, char *line, char letter);
void				get_colors(char *line, t_data *player, char param);
int					get_map_numbers(int fd_open, t_data *player);
void				get_map(t_data *player, char *line);
void				get_textures(t_data *player, char *line);
t_text				get_texture(t_data *player);
t_data				*init_player(char *argv[], int argc, int num_sprites);
void				render_bonus(t_data *player);
int					control_life_enemy(t_data *player, int posx, int posy);
void				render(t_data *player);
void				print_map(t_data *player);
void				print_column(t_data *player, int end, int coord,
					t_text texture);
int					hook_key_close(t_data *player);
int					hook_key_press(int key, t_data *player);
int					hook_key_release(int key, t_data *player);
int					exit_program(t_data *player);
#endif
