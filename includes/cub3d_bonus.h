/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 17:22:36 by pablo             #+#    #+#             */
/*   Updated: 2020/01/09 19:48:57 by pcuadrad         ###   ########.fr       */
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
# include <time.h>

typedef struct		map_s
{
	int		width;
	int 	height;
	int		screen_height;
	int		x_max;
	int		y_max;
	int		**tab_map;
}					map_t;

typedef struct		ray_s
{
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	int		mapX;
	int		mapY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	double	wallhit_x;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	int		seeprite;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	int		color;
}					ray_t;

typedef struct		color_s
{
	int		empty;
	int		r;
	int		g;
	int		b;
}					color_t;

typedef struct		image_s
{
	void	*id;
	int		*image;
	int		data;
	int		w;
	int		h;
	int		endian;
	int		size_line;
}					image_t;

typedef struct		text_c
{
	char	*path;
	void	*id;
	int		*image;
	int		data;
	int		w;
	int		h;
	int		endian;
	int		size_line;
}					text_t;

typedef struct		keys_s
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
}					keys_t;

typedef struct		textures_s
{
	text_t	north_text;
	text_t	south_text;
	text_t	east_text;
	text_t	weast_text;
	text_t	layaout;
	text_t	gun;
	text_t	gunshot;
	text_t	*sprite;
	text_t	floor;
	text_t	ceilling;
	text_t	gameover;
}					textures_t;

typedef struct		valid_s
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
}					valid_t;

typedef struct		sprite_s
{
	double		posX;
	double		posY;
	int			n_text;
	int			hp;
}					sprite_t;

typedef struct		rays_s
{
	int			*spriteOrder;
	double		*spriteDistance;
	double		spriteX;
	double		spriteY;
	double		invDet;
	double		transformX;
	double		transformY;
	int			spriteScreenX;
	int			vMoveScreen;
	int			spriteHeight;
	int			drawStartY;
	int			drawEndY;
	int			spriteWidth;
	int			drawStartX;
	int			drawEndX;
	int			print_y;
}					rays_t;

typedef struct		floorceil_s
{
	double		floorXWall;
	double		floorYWall;
	double		distWall;
	double		distPlayer;
	double		currentDist;
	double		weight;
	double		currentFloorX;
	double		currentFloorY;
	int			floorTexX;
	int			floorTexY;
}					floorceil_t;

typedef struct		s_data
{
	void		*mlx_ptr;
	void		*mlx_win;
	int			init_game;
	int			argc;
	char		*argv[2];
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
	int			num_sprites;
	double		*depth;
	double		hp_max;
	double		hp_current;
	int			bullet_max;
	int			bullet_current;
	int			items_current;
	int			lifes;
	ray_t		ray;
	rays_t		ray_sprite;
	map_t		map;
	textures_t	textur;
	image_t		img;
	keys_t		keys;
	sprite_t	*sprite;
	floorceil_t	floorceilling;
}					t_data;

# define uDiv 1
# define vDiv 1
# define vMove 0.0
# define KEY_ESC 53
# define KEY_A 0
# define KEY_W 13
# define KEY_S 1
# define KEY_D 2
# define KEY_SPACE 49
# define KEY_ENTER 36
# define KEY_ARROW_LEFT 123
# define KEY_ARROW_UP 126
# define KEY_ARROW_RIGHT 124
# define KEY_ARROW_DOWN 125
# define SCREENSHOT_PATH "screenshot.bmp"
# define BYTES_PER_PIXEL 4
# define FILE_HEADER_SIZE 14
# define INFO_HEADER_SIZE 40

void	play_shot(t_data *player);
void	free_game(t_data *player);
int		charge_textures(t_data *player, text_t *texture);
void	init_game(int argc, char *argv[], int lifes);
void	update_screen(t_data *player);
void	enemy_attack(t_data *player);
void	animate_sprite(t_data *player);
void    floorcasting(t_data *player, int coord);
void	control_life(t_data *player);
int		shot(t_data *player);
void	change_sprite(t_data *player, int posX, int posY);
void	delete_sprite(t_data *player, int posX, int posY);
int		create_color(int r, int g, int b);
void	print_gun(t_data *player);
void	get_crosshair(t_data *player);
void	print_crosshair(t_data *player);
void	print_hud(t_data *player);
int		init_render(t_data *player);
void	bmp_check(t_data *player, char *argv[]);
double	ft_pow(double num);
int		get_color_bmp(unsigned char *image, int x, int y, t_data *player);
void	render_sprite(t_data *player);
void	free_all(t_data *player);
void	free_path_textures(t_data *player, int control);
void	parse_map(t_data *player, char *line);
int		isvalid(char *argv[]);
int		check_map(valid_t *check);
int		check_resolution(char *line, valid_t *check);
int		check_textures(char *line, valid_t *check);
int     check_sprite(char *line, valid_t *check, char letter);
int     check_color(char *line, valid_t *check);
void	ft_exit(int control);
void	free_all_bmp(t_data *player);
int		exit_program_bmp(t_data *player);
int		create_bmp(t_data *player);
text_t	get_texture(t_data *player);
int		rotate_player(t_data *player,  double rotSpeed);
int		up_down_player(t_data *player, double moveSpeed, double dirX, double dirY);
int		left_rigth_player(t_data *player, double moveSpeed, double planeX, double planeY);
int		get_next_line(int fd, char **line);
void	get_resolution(t_data *player, char *line);
int		check_map_bg(char *line);
void	create_map(char *line, int x, t_data *player, int *sp_x);
void	isfirst_or_last_line(char *line, t_data *player);
int		count_line(char *line);
void	charge_textures_main(t_data *player);
void	get_coordenate(t_data *player, char c);
void	get_sprite(t_data *player, char *line, char letter);
void	get_colors(char *line, t_data *player, char param);
int		get_map_numbers(int fd_open, t_data *player);
void	get_map(t_data *player, char *line);
void	get_textures(t_data *player, char *line);
t_data	*init_player(char *argv[], int argc, int num_sprites, int lifes);
void	render(t_data *player);
void	print_map(t_data *player);
void	print_column(t_data *player, int start, int end, int coord, text_t texture);
int		hook_key_close(t_data *player);
int		hook_key_press(int key, t_data *player);
int		hook_key_release(int key, t_data *player);
int		exit_program(t_data *player);
#endif
