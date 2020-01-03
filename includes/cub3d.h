/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 17:22:36 by pablo             #+#    #+#             */
/*   Updated: 2020/01/03 12:26:56 by pcuadrad         ###   ########.fr       */
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

typedef struct		map_s
{
	int		width;
	int 	height;
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
	double	wallhit_y;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
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
}					keys_t;

typedef struct		textures_s
{
	text_t	north_text;
	text_t	south_text;
	text_t	east_text;
	text_t	weast_text;
	text_t	sprite;
	color_t	floor_color;
	color_t	ceilling_color;
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

typedef struct		data_s
{
	void		*mlx_ptr;
	void		*mlx_win;
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
	int			num_sprites;
	double		*depth;
	ray_t		ray;
	rays_t		ray_sprite;
	map_t		map;
	textures_t	textur;
	image_t		img;
	keys_t		keys;
	sprite_t	*sprite;
}					data_t;


/*
For Linux:
# define KEY_ESC 65307
# define KEY_A 97
# define KEY_W 119
# define KEY_S 115
# define KEY_D 100
# define KEY_ARROW_LEFT 65361
# define KEY_ARROW_UP 65362
# define KEY_ARROW_RIGHT 65363
# define KEY_ARROW_DOWN 65364
*/

// For MAC
# define uDiv 1
# define vDiv 1
# define vMove 0.0
# define KEY_ESC 53
# define KEY_A 0
# define KEY_W 13
# define KEY_S 1
# define KEY_D 2
# define KEY_ARROW_LEFT 123
# define KEY_ARROW_UP 126
# define KEY_ARROW_RIGHT 124
# define KEY_ARROW_DOWN 125
# define SCREENSHOT_PATH "screenshot.bmp"
# define BYTES_PER_PIXEL 4
# define INFO_HEADER_SIZE 54

int		init_render(data_t *player);
void	bmp_check(data_t *player, char *argv[]);
double	ft_pow(double num);
void	render_sprite(data_t *player);
void	free_all(data_t *player);
void	free_path_textures(data_t *player, int control);
void	parse_map(data_t *player, char *line);
int		isvalid(char *argv[]);
int		check_map(valid_t *check);
int		check_resolution(char *line, valid_t *check);
int		check_textures(char *line, valid_t *check);
int     check_sprite(char *line, valid_t *check);
int     check_color(char *line, valid_t *check);
void	ft_exit(int control);
int		create_bmp(data_t *player);
text_t	get_texture(data_t *player);
int		rotate_player(data_t *player,  double rotSpeed);
int		up_down_player(data_t *player, double moveSpeed, double dirX, double dirY);
int		left_rigth_player(data_t *player, double moveSpeed, double planeX, double planeY);
int		get_next_line(int fd, char **line);
void	get_resolution(data_t *player, char *line);
int		check_map_bg(char *line);
void	create_map(char *line, int x, data_t *player, int *sp_x);
void	isfirst_or_last_line(char *line, data_t *player);
int		count_line(char *line);
void	charge_textures_main(data_t *player);
void	get_coordenate(data_t *player, char c);
void	get_sprite(data_t *player, char *line);
void	get_colors(char *line, color_t *color, char param);
int		get_map_numbers(int fd_open, data_t *player);
void	get_map(data_t *player, char *line);
void	get_textures(data_t *player, char *line);
data_t	*init_player(char *argv[], int argc, int num_sprites);
void	render(data_t *player);
void	print_map(data_t *player);
void	print_column(data_t *player, int start, int end, int coord, text_t texture);
int		hook_key_close(data_t *player);
int		hook_key_press(int key, data_t *player);
int		hook_key_release(int key, data_t *player);
int		exit_program(data_t *player);
#endif
