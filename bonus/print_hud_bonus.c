/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hud_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 11:36:01 by pcuadrad          #+#    #+#             */
/*   Updated: 2019/12/30 14:30:38 by pcuadrad         ###   ########.fr       */
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

void		print_hud(data_t *player)
{
	int		y;
	int		x;
	double	how_x;
	double	how_y;

	//Relleno de textura
	x = -1;
	while (++x < player->map.width)
	{
		how_x = (x * player->textur.layaout.w) / player->map.width;
		y = player->map.height - 1;
		while (++y < player->map.screen_height)
		{
			how_y = (y * (player->map.screen_height - player->map.height)) / player->textur.layaout.h;
			player->img.image[(y * player->map.width) + x] = get_pixel(&player->textur.layaout, how_y, how_x);
		}
	}
	//Bordes negros
	x = -1;
	how_x = player->map.width / 30;
	how_y = (player->map.screen_height - player->map.height) / 8;
	while (++x < player->map.width)
	{
		y = player->map.height - 1;
		while (++y < player->map.screen_height)
		{
			if (((x < how_x) || (x > player->map.width - how_x)) || ((y < player->map.height + how_y) || (y > player->map.screen_height - how_y)))
				player->img.image[(y * player->map.width) + x] = 0;
		}
	}
	//Barra de vida
	x = (player->map.width / 2) + (how_x * 2) - 1;
	int hpwidth = (player->map.width - (how_x * 2)) - x;
	int hp = ((player->hp_current * hpwidth) / 100) + x;
	hpwidth = hpwidth + x;
	while (++x < player->map.width - (how_x * 2))
	{
		y = (player->map.height + (how_y * 2)) - 1;
		while (++y < (player->map.screen_height - (how_y * 2)))
		{
			if (x <= hp)
			{
				if (player->hp_current > 60)
					player->img.image[(y * player->map.width) + x] = create_color(125, 130, 0);
				else if (player->hp_current > 30 && player->hp_current < 60)
					player->img.image[(y * player->map.width) + x] = create_color(220, 175, 0);
				else
					player->img.image[(y * player->map.width) + x] = create_color(255, 0, 0);
			}
			else if (x > hp && x < hpwidth)
				player->img.image[(y * player->map.width) + x] = create_color(255, 255, 255);
			else
				player->img.image[(y * player->map.width) + x] = create_color(0, 0, 0);
		}
	}
	//Borde barra de vida
	x = (player->map.width / 2) + (how_x * 2) - 1;
	hpwidth = (player->map.width - (how_x * 2)) - x;
	int hpheigth = ((player->map.screen_height - (how_y * 2))) - ((player->map.height + (how_y * 2)));
	int how_xlf = (hpwidth / 20) + x;
	int how_ylf = ((player->map.height + (how_y * 2))) + (hpheigth / 6);
	int	resx = (how_xlf - x);
	resx = (int)((player->map.width - (how_x * 2)) - resx);
	int	resy = (player->map.screen_height - (how_y * 2) - (hpheigth / 6));
	while (++x < player->map.width - (how_x * 2))
	{
		y = (player->map.height + (how_y * 2)) - 1;
		while (++y < (player->map.screen_height - (how_y * 2)))
		{
			if ((x < how_xlf || x > resx) || ((y < how_ylf || y > resy)))
				player->img.image[(y * player->map.width) + x] = 0;
		}
	}
}

void			print_crosshair(data_t *player)
{
	int		x;
	int		y;

	x = player->keys.x_begin - 1;
	while (++x < player->keys.x_end)
	{
		y = player->keys.y_begin - 1;
		while (++y < player->keys.y_end)
		{
			if (((x < player->map.width / 2) && (y > ((player->map.height / 2) - 2) && y < ((player->map.height / 2) + 2)))
				|| (x > ((player->map.width / 2) - 2) && x < ((player->map.width / 2) + 2)) || (x > player->map.width / 2
					&& (y > ((player->map.height / 2) - 2) && y < ((player->map.height / 2) + 2))))
				player->img.image[(y * player->map.width) + x] = create_color(255, 255, 255);
		}
	}
}

void			print_gun(data_t *player)
{
	int		x_bgin;
	int		x_end;
	int		y_bgin;
	int		y_end;
	double	how_x;
	double	how_y;
	int		x;
	int		y;
	int		x_0;
	int		y_0;
	unsigned int color;
	
	x_bgin = player->map.width / 3;
	x_end = player->map.width - x_bgin;
	y_bgin = player->map.height / 3;
	y_bgin = player->map.height - y_bgin;
	y_end = player->map.height;
	x = x_bgin - 1;
	x_0 = 0;
	while (++x < x_end)
	{
		how_x = ((x_0++ * player->textur.gun.w) / (x_end - x_bgin));
		y = y_bgin - 1;
		y_0 = 0;
		while (++y < y_end)
		{
			how_y = ((y_0++ * player->textur.gun.h) / (y_end - y_bgin));
			color = get_pixel(&player->textur.gun, how_y, how_x);
			if (color != 4278190080)
				player->img.image[(y * player->map.width) + x] = color;
		}
	}
}