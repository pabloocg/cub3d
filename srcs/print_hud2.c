/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hud2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 13:25:34 by pcuadrad          #+#    #+#             */
/*   Updated: 2020/01/10 13:59:14 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void		print_texture_layaout(t_data *player)
{
	int		y;
	int		x;
	double	how_x;
	double	how_y;

	x = -1;
	while (++x < player->map.width)
	{
		how_x = (x * player->textur.layaout.w) / player->map.width;
		y = player->map.height - 1;
		while (++y < player->map.screen_height)
		{
			how_y = (y * (player->map.screen_height - player->map.height)) /
			player->textur.layaout.h;
			player->img.image[(y * player->map.width) + x] = get_pixel(&player->
			textur.layaout, how_y, how_x);
		}
	}
}

void		print_black_layaout(t_data *player)
{
	int		y;
	int		x;
	double	how_x;
	double	how_y;

	x = -1;
	how_x = player->map.width / 30;
	how_y = (player->map.screen_height - player->map.height) / 8;
	while (++x < player->map.width)
	{
		y = player->map.height - 1;
		while (++y < player->map.screen_height)
		{
			if (((x < how_x) || (x > player->map.width - how_x)) || ((y <
				player->map.height + how_y) || (y > player->map.screen_height -
				how_y)))
				player->img.image[(y * player->map.width) + x] = 0;
		}
	}
}

void		print_black_hp(t_data *player, int hpwidth, double how_y,
			double how_x)
{
	player->hp.x = (player->map.width / 2) + (how_x * 2) - 1;
	hpwidth = (player->map.width - (how_x * 2)) - player->hp.x;
	player->hp.hpheigth = ((player->map.screen_height - (how_y * 2))) -
				((player->map.height + (how_y * 2)));
	player->hp.how_xlf = (hpwidth / 20) + player->hp.x;
	player->hp.how_ylf = ((player->map.height + (how_y * 2))) +
	(player->hp.hpheigth / 6);
	player->hp.resx = (player->hp.how_xlf - player->hp.x);
	player->hp.resx = (int)((player->map.width - (how_x * 2)) -
	player->hp.resx);
	player->hp.resy = (player->map.screen_height - (how_y * 2) -
	(player->hp.hpheigth / 6));
	while (++player->hp.x < player->map.width - (how_x * 2))
	{
		player->hp.y = (player->map.height + (how_y * 2)) - 1;
		while (++player->hp.y < (player->map.screen_height - (how_y * 2)))
		{
			if ((player->hp.x < player->hp.how_xlf || player->hp.x > player->
				hp.resx) || ((player->hp.y < player->hp.how_ylf || player->hp.y
				> player->hp.resy)))
				player->img.image[(player->hp.y * player->map.width) +
				player->hp.x] = 0;
		}
	}
}

void		print_hp(t_data *player)
{
	init_print_hp(player);
	while ((++player->hp.x < player->map.width - (player->hp.how_x * 2)) &&
			(player->hp.y = (player->map.height + (player->hp.how_y * 2)) - 1))
		while (++player->hp.y < (player->map.screen_height -
			(player->hp.how_y * 2)))
			if (player->hp.x <= player->hp.hp)
			{
				if (player->hp_current > 60)
					player->img.image[(player->hp.y * player->map.width) +
					player->hp.x] = create_color(125, 130, 0);
				else if (player->hp_current > 30 && player->hp_current < 60)
					player->img.image[(player->hp.y * player->map.width) +
					player->hp.x] = create_color(220, 175, 0);
				else
					player->img.image[(player->hp.y * player->map.width) +
					player->hp.x] = create_color(255, 0, 0);
			}
			else if (player->hp.x > player->hp.hp && player->hp.x <
				player->hp.hpwidth)
				player->img.image[(player->hp.y * player->map.width) +
				player->hp.x] = create_color(255, 255, 255);
			else
				player->img.image[(player->hp.y * player->map.width) +
				player->hp.x] = create_color(0, 0, 0);
}

void		print_hud(t_data *player)
{
	print_texture_layaout(player);
	print_black_layaout(player);
	print_hp(player);
	print_black_hp(player, player->hp.hpwidth, player->hp.how_y,
	player->hp.how_x);
}
