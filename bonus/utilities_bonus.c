/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 19:28:28 by pcuadrad          #+#    #+#             */
/*   Updated: 2019/12/31 16:48:11 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static int	get_pixel(text_t *image, double y, double x)
{
	int		pos;

	if (x < 0 || y < 0 || x > image->w || y > image->h)
		return (0);
	pos = ((int)(double)((y * image->w) + x));
	return ((int)image->image[(int)pos]);
}

double		ft_pow(double num)
{
	return (num * num);
}

void	ft_exit(int control)
{
	if (control == 1)
		ft_printf("The file is not valid!\n");
	else if (control == 2)
		ft_printf("Wrong parameters.\nPlease fixed!!\n");
	else if (control == 3)
		ft_printf("Error\nThe syntax is ./cub3D < file.cub > < --save >\n");
	else if (control == 4)
		ft_printf("Fail charging textures.\n");
	else if (control == 5)
		ft_printf("Error malloc allocate memory.\n");
	exit(EXIT_FAILURE);
}

int		exit_program(data_t *player)
{
	free_all(player);
	ft_printf("Saliendo del programa..\n");
	exit(EXIT_SUCCESS);
}

void	get_crosshair(data_t *player)
{
	player->keys.x_begin = (player->map.width / 2) - player->map.width / 50;
	player->keys.x_end = (player->map.width / 2) + player->map.width / 50;
	player->keys.y_begin = (player->map.height / 2) - player->map.height / 40;
	player->keys.y_end = (player->map.height / 2) + player->map.height / 40;
}

int		create_color(int r, int g, int b)
{
	int		color;

	color = r;
	color = (color << 8) | g;
	color = (color << 8) | b;
	return (color);
}

void		game_over(data_t *player)
{
	int x;
	int	how_x;
	int how_y;
	int y;

	player->init_game = 1;
	player->textur.gameover.path = ft_strdup("textures/game_over.xpm");
	charge_textures(player, &player->textur.gameover);
	x = -1;
	while (++x < player->map.width)
	{
		how_x = (x * player->textur.gameover.w) / player->map.width;
		y = -1;
		while (++y < player->map.screen_height)
		{
			how_y = (y * player->textur.gameover.h ) / player->map.screen_height;
			player->img.image[(y * player->map.width) + x] = get_pixel(&player->textur.gameover, how_y, how_x);
		}
	}
	mlx_put_image_to_window(player->mlx_ptr, player->mlx_win, player->img.id,
	0, 0);
	mlx_string_put(player->mlx_ptr, player->mlx_win, player->map.width / 3,
	player->map.screen_height / 3, create_color(255, 255, 255), "PRESS ESC TO EXIT");
	mlx_string_put(player->mlx_ptr, player->mlx_win, player->map.width / 3,
	player->map.screen_height - player->map.screen_height / 3, create_color(255, 255, 255), "PRESS ENTER TO PLAY");
	mlx_hook(player->mlx_win, 17, 0, &exit_program, player);
	mlx_hook(player->mlx_win, 2, 0, &hook_key_press, player);
	mlx_loop(player->mlx_ptr);
}
void		control_life(data_t *player)
{
	if (player->hp_current > player->hp_max)
		player->hp_current = player->hp_max;
	if (player->hp_current < 0)
		player->hp_current = 0.;
	if ((int)player->hp_current == 0)
		game_over(player);
}