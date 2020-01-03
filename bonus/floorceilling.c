/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floorceilling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 16:35:30 by pcuadrad          #+#    #+#             */
/*   Updated: 2019/12/28 18:23:06 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static int	get_pixel(text_t *image, int y, int x)
{
	int		pos;

	if (x < 0 || y < 0 || x > image->w || y > image->h)
		return (0);
	pos = ((int)(double)((y * image->w) + x));
	return ((int)image->image[(int)pos]);
}

static void	get_floorXWall(data_t *player)
{
	if(player->ray.side == 0 && player->ray.stepX > 0)
	{
		player->floorceilling.floorXWall = player->ray.mapX;
		player->floorceilling.floorYWall = player->ray.mapY +
			player->ray.wallhit_x;
	}
	else if(player->ray.side == 0 && player->ray.stepX < 0)
	{
		player->floorceilling.floorXWall = player->ray.mapX + 1.0;
		player->floorceilling.floorYWall = player->ray.mapY +
			player->ray.wallhit_x;
	}
	else if(player->ray.side == 1 && player->ray.stepY > 0)
	{
		player->floorceilling.floorXWall = player->ray.mapX +
			player->ray.wallhit_x;
		player->floorceilling.floorYWall = player->ray.mapY;
	}
	else
	{
		player->floorceilling.floorXWall = player->ray.mapX +
			player->ray.wallhit_x;
		player->floorceilling.floorYWall = player->ray.mapY + 1.0;
	}
}

static void	how_xy(data_t *player, int y)
{
	player->floorceilling.currentDist = player->map.height /
		(2.0 * y - player->map.height);
	player->floorceilling.weight = (player->floorceilling.currentDist -
		player->floorceilling.distPlayer) / (player->floorceilling.distWall -
		player->floorceilling.distPlayer);
	player->floorceilling.currentFloorX = player->floorceilling.weight *
		player->floorceilling.floorXWall + (1.0 - player->floorceilling.weight)
		* player->posX;
	player->floorceilling.currentFloorY = player->floorceilling.weight *
		player->floorceilling.floorYWall + (1.0 - player->floorceilling.weight)
		* player->posY;
	player->floorceilling.floorTexX = (int)(player->floorceilling.currentFloorX
		* player->textur.floor.w) % player->textur.floor.w;
	player->floorceilling.floorTexY = (int)(player->floorceilling.currentFloorY
		* player->textur.floor.h) % player->textur.floor.h;
}

void        floorcasting(data_t *player, int coord)
{
    int     y;

	get_floorXWall(player);
	player->floorceilling.distWall = player->ray.perpWallDist;
	player->floorceilling.distPlayer = 0.0;
	if (player->ray.drawEnd < 0)
		player->ray.drawEnd = player->map.height;
	y = player->ray.drawEnd - 1;
	while (++y < player->map.height)
	{
		how_xy(player, y);
		player->img.image[(y * player->map.width) + coord] =
			get_pixel(&player->textur.floor, player->floorceilling.floorTexY,
			player->floorceilling.floorTexX);
		player->img.image[((player->map.height - y) * player->map.width) + coord] =
			get_pixel(&player->textur.ceilling, player->floorceilling.floorTexY,
			player->floorceilling.floorTexX);
	}
}