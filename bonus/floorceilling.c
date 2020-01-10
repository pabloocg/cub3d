/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floorceilling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 16:35:30 by pcuadrad          #+#    #+#             */
/*   Updated: 2020/01/10 12:55:46 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	get_floorxwall(t_data *player)
{
	if (player->ray.side == 0 && player->ray.stepx > 0)
	{
		player->floorceilling.floorxwall = player->ray.mapx;
		player->floorceilling.floorywall = player->ray.mapy +
			player->ray.wallhit_x;
	}
	else if (player->ray.side == 0 && player->ray.stepx < 0)
	{
		player->floorceilling.floorxwall = player->ray.mapx + 1.0;
		player->floorceilling.floorywall = player->ray.mapy +
			player->ray.wallhit_x;
	}
	else if (player->ray.side == 1 && player->ray.stepy > 0)
	{
		player->floorceilling.floorxwall = player->ray.mapx +
			player->ray.wallhit_x;
		player->floorceilling.floorywall = player->ray.mapy;
	}
	else
	{
		player->floorceilling.floorxwall = player->ray.mapx +
			player->ray.wallhit_x;
		player->floorceilling.floorywall = player->ray.mapy + 1.0;
	}
}

static void	how_xy(t_data *player, int y)
{
	player->floorceilling.currentdist = player->map.height /
		(2.0 * y - player->map.height);
	player->floorceilling.weight = (player->floorceilling.currentdist -
		player->floorceilling.distplayer) / (player->floorceilling.distwall -
		player->floorceilling.distplayer);
	player->floorceilling.currentfloorx = player->floorceilling.weight *
		player->floorceilling.floorxwall + (1.0 - player->floorceilling.weight)
		* player->posx;
	player->floorceilling.currentfloory = player->floorceilling.weight *
		player->floorceilling.floorywall + (1.0 - player->floorceilling.weight)
		* player->posy;
	player->floorceilling.floortex = (int)(player->floorceilling.currentfloorx
		* player->textur.floor.w) % player->textur.floor.w;
	player->floorceilling.floortexy = (int)(player->floorceilling.currentfloory
		* player->textur.floor.h) % player->textur.floor.h;
}

void		floorcasting(t_data *player, int coord)
{
	int		y;

	get_floorxwall(player);
	player->floorceilling.distwall = player->ray.perpwalldist;
	player->floorceilling.distplayer = 0.0;
	if (player->ray.drawend < 0)
		player->ray.drawend = player->map.height;
	y = player->ray.drawend - 1;
	while (++y < player->map.height)
	{
		how_xy(player, y);
		player->img.image[(y * player->map.width) + coord] =
			get_pixel(&player->textur.floor, player->floorceilling.floortexy,
			player->floorceilling.floortex);
		player->img.image[((player->map.height - y) * player->map.width) +
		coord] = get_pixel(&player->textur.ceilling, player->floorceilling.
		floortexy, player->floorceilling.floortex);
	}
}
