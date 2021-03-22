/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_bonus_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 11:39:41 by pcuadrad          #+#    #+#             */
/*   Updated: 2020/01/10 13:22:04 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void		get_crosshair(t_data *player)
{
	player->keys.x_begin = (player->map.width / 2) - player->map.width / 50;
	player->keys.x_end = (player->map.width / 2) + player->map.width / 50;
	player->keys.y_begin = (player->map.height / 2) - player->map.height / 40;
	player->keys.y_end = (player->map.height / 2) + player->map.height / 40;
}

void		put_image_game_over(t_data *player)
{
	int		x;
	int		y;
	int		how_x;
	int		how_y;

	x = -1;
	while ((++x < player->map.width) && (y = -1))
	{
		how_x = (x * player->textur.gameover.w) / player->map.width;
		while (++y < player->map.screen_height)
		{
			how_y = (y * player->textur.gameover.h) / player->map.screen_height;
			player->img.image[(y * player->map.width) + x] = get_pixel(&player->
			textur.gameover, how_y, how_x);
		}
	}
}

void		game_over(t_data *player)
{
	player->init_game = 1;
	player->textur.gameover.path = ft_strdup("textures/game_over.xpm");
	charge_textures(player, &player->textur.gameover);
	put_image_game_over(player);
	mlx_put_image_to_window(player->mlx_ptr, player->mlx_win, player->img.id,
	0, 0);
	mlx_string_put(player->mlx_ptr, player->mlx_win, player->map.width / 3,
	player->map.screen_height / 3, create_color(255, 255, 255),
	"PRESS ESC TO EXIT");
	mlx_string_put(player->mlx_ptr, player->mlx_win, player->map.width / 3,
	player->map.screen_height / 5, create_color(255, 255, 255),
	"PRESS ENTER TO PLAY");
	mlx_hook(player->mlx_win, 17, 0, &exit_program, player);
	mlx_hook(player->mlx_win, 2, 0, &hook_key_press, player);
	mlx_loop(player->mlx_ptr);
}

void		control_life(t_data *player)
{
	if (player->hp_current > player->hp_max)
		player->hp_current = player->hp_max;
	if (player->hp_current < 0)
		player->hp_current = 0.;
	if ((int)player->hp_current == 0)
		game_over(player);
}

int			get_color_bmp(unsigned char *image, int x, int y, t_data *player)
{
	int		rgb;
	int		color;

	color = *(int*)(image + (4 * player->map.width * (player->map.screen_height
	- 1 - y)) + (4 * x));
	rgb = (color & 0xFF0000) | (color & 0x00FF00) | (color & 0x0000FF);
	return (rgb);
}
