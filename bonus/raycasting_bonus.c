/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playering.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 20:24:56 by pablo             #+#    #+#             */
/*   Updated: 2019/12/06 14:38:32 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static	void	get_wall_hit(t_data *player)
{
	 if (player->ray.side == 1)
        player->ray.wallhit_x = player->posX + ((player->ray.mapY - player->posY + (1 - player->ray.stepY) / 2)
            / player->ray.rayDirY) * player->ray.rayDirX;
    else
        player->ray.wallhit_x = player->posY + ((player->ray.mapX - player->posX + (1 - player->ray.stepX) / 2)
            / player->ray.rayDirX) * player->ray.rayDirY;
	player->ray.wallhit_x -= floor(player->ray.wallhit_x);
}

static void	get_distance(t_data *player, int x)
{

	if (player->ray.side == 0)
		player->ray.perpWallDist = fabs((player->ray.mapX - player->posX +
			(1 - player->ray.stepX) / 2.) / player->ray.rayDirX);
	else
		player->ray.perpWallDist = fabs((player->ray.mapY - player->posY +
			(1 - player->ray.stepY) / 2.) / player->ray.rayDirY);
	player->depth[x] = player->ray.perpWallDist;
	player->ray.lineHeight = (int)(player->map.height /
	player->ray.perpWallDist);
	player->ray.drawStart = (-player->ray.lineHeight / 2) +
	(player->map.height / 2);
	player->ray.drawStart = (player->ray.drawStart < 0) ?
	0 : player->ray.drawStart;
	player->ray.drawEnd = (player->ray.lineHeight / 2) +
		(player->map.height / 2);
	player->ray.drawEnd = (player->ray.drawEnd >= player->map.height) ?
	player->map.height - 1 : player->ray.drawEnd;
}

static void	get_hit(t_data *player)
{
	player->ray.hit = 0;
	while (player->ray.hit == 0)
	{
		if (player->ray.sideDistX < player->ray.sideDistY)
		{
			player->ray.sideDistX += player->ray.deltaDistX;
			player->ray.mapX += player->ray.stepX;
			player->ray.side = 0;
		}
		else
		{
			player->ray.sideDistY += player->ray.deltaDistY;
			player->ray.mapY += player->ray.stepY;
			player->ray.side = 1;
		}
		if (player->map.tab_map[player->ray.mapX][player->ray.mapY] == 1)
			player->ray.hit = 1;
		else if (player->map.tab_map[player->ray.mapX][player->ray.mapY] == 3)
			player->ray.seeprite = 2;
	}
}

static void	get_step_side(int x, t_data *player)
{
	player->ray.cameraX = (2 * x) / (double)player->map.width - 1;
	player->ray.rayDirX = player->dirX + player->planeX * player->ray.cameraX;
	player->ray.rayDirY = player->dirY + player->planeY * player->ray.cameraX;
	player->ray.mapX = (int)player->posX;
	player->ray.mapY = (int)player->posY;
	player->ray.deltaDistX = sqrt(1 + ((ft_pow(player->ray.rayDirY)) /
		(ft_pow(player->ray.rayDirX))));
	player->ray.deltaDistY = sqrt(1 + ((ft_pow(player->ray.rayDirX)) /
		(ft_pow(player->ray.rayDirY))));
	player->ray.stepX = (player->ray.rayDirX < 0) ? -1 : 1;
	if (player->ray.rayDirX < 0)
		player->ray.sideDistX = (player->posX - player->ray.mapX) *
								player->ray.deltaDistX;
	else
		player->ray.sideDistX = (player->ray.mapX + 1.0 - player->posX) *
								player->ray.deltaDistX;
	player->ray.stepY = (player->ray.rayDirY < 0) ? -1 : 1;
	if (player->ray.rayDirY < 0)
		player->ray.sideDistY = (player->posY - player->ray.mapY) *
								player->ray.deltaDistY;
	else
		player->ray.sideDistY = (player->ray.mapY + 1.0 - player->posY) *
								player->ray.deltaDistY;
}

void			render_bonus(t_data *player)
{
	if (player->ray.seeprite != 0)
		enemy_attack(player);
	if (player->init_game == 0)
	{
		control_life(player);
		animate_sprite(player);
		render_sprite(player);
		print_map(player);
		print_hud(player);
		print_crosshair(player);
		print_gun(player);
	}
}

void			render(t_data *player)
{
	int		x;

	ft_bzero(player->img.image, player->map.width * player->map.screen_height);
	player->ray.seeprite = 0;
	x = -1;
	while (++x < player->map.width)
	{
		get_step_side(x, player);
		get_hit(player);
		get_distance(player, x);
		get_wall_hit(player);
		print_column(player, player->ray.drawStart, player->ray.drawEnd, x,
			get_texture(player));
		floorcasting(player, x);
	}
	render_bonus(player);
}
