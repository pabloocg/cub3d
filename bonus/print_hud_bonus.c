/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hud_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 11:36:01 by pcuadrad          #+#    #+#             */
/*   Updated: 2020/01/10 13:59:39 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void			init_print_hp(t_data *player)
{
	player->hp.how_x = player->map.width / 30;
	player->hp.how_y = (player->map.screen_height - player->map.height) / 8;
	player->hp.x = (player->map.width / 2) + (player->hp.how_x * 2) - 1;
	player->hp.hpwidth = (player->map.width - (player->hp.how_x * 2)) -
	player->hp.x;
	player->hp.hp = ((player->hp_current * player->hp.hpwidth) / 100) +
	player->hp.x;
	player->hp.hpwidth = player->hp.hpwidth + player->hp.x;
}

void			print_crosshair(t_data *player)
{
	int		x;
	int		y;

	x = player->keys.x_begin - 1;
	while (++x < player->keys.x_end)
	{
		y = player->keys.y_begin - 1;
		while (++y < player->keys.y_end)
		{
			if (((x < player->map.width / 2) && (y > ((player->map.height / 2)
				- 2) && y < ((player->map.height / 2) + 2)))
				|| (x > ((player->map.width / 2) - 2) && x < ((player->map.width
				/ 2) + 2)) || (x > player->map.width / 2
					&& (y > ((player->map.height / 2) - 2) && y < ((player->
					map.height / 2) + 2))))
				player->img.image[(y * player->map.width) + x] =
					create_color(255, 255, 255);
		}
	}
}

void			print_gun(t_data *player)
{
	player->gun.x_bgin = player->map.width / 3;
	player->gun.x_end = player->map.width - player->gun.x_bgin;
	player->gun.y_bgin = player->map.height / 3;
	player->gun.y_bgin = player->map.height - player->gun.y_bgin;
	player->gun.y_end = player->map.height;
	player->gun.x = player->gun.x_bgin - 1;
	player->gun.x_0 = 0;
	while (++player->gun.x < player->gun.x_end)
	{
		player->gun.how_x = ((player->gun.x_0++ * player->textur.gun.w) /
		(player->gun.x_end - player->gun.x_bgin));
		player->gun.y = player->gun.y_bgin - 1;
		player->gun.y_0 = 0;
		while (++player->gun.y < player->gun.y_end)
		{
			player->gun.how_y = ((player->gun.y_0++ * player->textur.gun.h) /
			(player->gun.y_end - player->gun.y_bgin));
			player->gun.color = get_pixel(&player->textur.gun, player->gun.how_y
			, player->gun.how_x);
			if (player->gun.color != 4278190080)
				player->img.image[(player->gun.y * player->map.width) +
				player->gun.x] = player->gun.color;
		}
	}
}
