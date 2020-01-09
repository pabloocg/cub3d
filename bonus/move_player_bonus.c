/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 12:05:26 by pcuadrad          #+#    #+#             */
/*   Updated: 2020/01/09 18:51:02 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int				up_down_player(t_data *player, double moveSpeed, double dirX, double dirY)
{
	if(player->map.tab_map[(int)(player->posX + dirX * 1)][(int)player->posY] == 6)
	{
		if ((player->bullet_current += 5) > player->bullet_max)
			player->bullet_current = player->bullet_max;
		delete_sprite(player, (int)(player->posX + dirX * 1), (int)player->posY);
		player->map.tab_map[(int)(player->posX + dirX * 1)][(int)player->posY] = 0;
	}
	if (player->map.tab_map[(int)player->posX][(int)(player->posY + dirY * 1)] == 6)
	{
		if ((player->bullet_current += 5) > player->bullet_max)
			player->bullet_current = player->bullet_max;
		delete_sprite(player, (int)player->posX, (int)(player->posY + dirY * 1));
		player->map.tab_map[(int)player->posX][(int)(player->posY + dirY * 1)] = 0;
	}
	if(player->map.tab_map[(int)(player->posX + dirX * 1)][(int)player->posY] == 5)
	{
		player->items_current += 1;
		delete_sprite(player, (int)(player->posX + dirX * 1), (int)player->posY);
		player->map.tab_map[(int)(player->posX + dirX * 1)][(int)player->posY] = 0;
	}
	if (player->map.tab_map[(int)player->posX][(int)(player->posY + dirY * 1)] == 5)
	{
		player->items_current += 1;
		delete_sprite(player, (int)player->posX, (int)(player->posY + dirY * 1));
		player->map.tab_map[(int)player->posX][(int)(player->posY + dirY * 1)] = 0;
	}
	if(player->map.tab_map[(int)(player->posX + dirX * 1)][(int)player->posY] == 4)
	{
		player->hp_current += 30.;
		control_life(player);
		delete_sprite(player, (int)(player->posX + dirX * 1), (int)player->posY);
		player->map.tab_map[(int)(player->posX + dirX * 1)][(int)player->posY] = 0;
	}
	if (player->map.tab_map[(int)player->posX][(int)(player->posY + dirY * 1)] == 4)
	{
		player->hp_current += 30.;
		control_life(player);
		delete_sprite(player, (int)player->posX, (int)(player->posY + dirY * 1));
		player->map.tab_map[(int)player->posX][(int)(player->posY + dirY * 1)] = 0;
	}
	if(player->map.tab_map[(int)(player->posX + dirX * 1)][(int)player->posY] == 0)
		player->posX += dirX * moveSpeed;
	if(player->map.tab_map[(int)player->posX][(int)(player->posY + dirY * 1)] == 0)
		player->posY += dirY * moveSpeed;
	return (1);
}

int				left_rigth_player(t_data *player, double moveSpeed, double planeX, double planeY)
{
	if(player->map.tab_map[(int)(player->posX + planeX * 1)][(int)player->posY] == 6)
	{
		if ((player->bullet_current += 5) > player->bullet_max)
			player->bullet_current = player->bullet_max;
		delete_sprite(player, (int)(player->posX + planeX * 1), (int)player->posY);
		player->map.tab_map[(int)(player->posX + planeX * 1)][(int)player->posY] = 0;
	}
	if (player->map.tab_map[(int)player->posX][(int)(player->posY + planeY * 1)] == 6)
	{
		if ((player->bullet_current += 5) > player->bullet_max)
			player->bullet_current = player->bullet_max;
		delete_sprite(player, (int)player->posX, (int)(player->posY + planeY * 1));
		player->map.tab_map[(int)player->posX][(int)(player->posY + planeY * 1)] = 0;
	}
	if(player->map.tab_map[(int)(player->posX + planeX * 1)][(int)player->posY] == 5)
	{
		player->items_current += 1;
		delete_sprite(player, (int)(player->posX + planeX * 1), (int)player->posY);
		player->map.tab_map[(int)(player->posX + planeX * 1)][(int)player->posY] = 0;
	}
	if (player->map.tab_map[(int)player->posX][(int)(player->posY + planeY * 1)] == 5)
	{
		player->items_current += 1;
		delete_sprite(player, (int)player->posX, (int)(player->posY + planeY * 1));
		player->map.tab_map[(int)player->posX][(int)(player->posY + planeY * 1)] = 0;
	}
	if(player->map.tab_map[(int)(player->posX + planeX * 1)][(int)player->posY] == 4)
	{
		player->hp_current += 30.;
		control_life(player);
		delete_sprite(player, (int)(player->posX + planeX * 1), (int)player->posY);
		player->map.tab_map[(int)(player->posX + planeX * 1)][(int)player->posY] = 0;
	}
	if (player->map.tab_map[(int)player->posX][(int)(player->posY + planeY * 1)] == 4)
	{
		player->hp_current += 30.;
		control_life(player);
		delete_sprite(player, (int)player->posX, (int)(player->posY + planeY * 1));
		player->map.tab_map[(int)player->posX][(int)(player->posY + planeY * 1)] = 0;
	}
	if(player->map.tab_map[(int)(player->posX + planeX * 1)][(int)player->posY] == 0)
		player->posX += planeX * moveSpeed;
	if(player->map.tab_map[(int)player->posX][(int)(player->posY + planeY * 1)] == 0)
		player->posY += planeY * moveSpeed;
	return (1);
}

int				rotate_player(t_data *player,  double rotSpeed)
{
	double oldDirX;
	double oldPlaneX;

	oldDirX = player->dirX;
	player->dirX = player->dirX * cos(rotSpeed) - player->dirY * sin(rotSpeed);
	player->dirY = oldDirX * sin(rotSpeed) + player->dirY * cos(rotSpeed);
	oldPlaneX = player->planeX;
	player->planeX = player->planeX * cos(rotSpeed) - player->planeY * sin(rotSpeed);
	player->planeY = oldPlaneX * sin(rotSpeed) + player->planeY * cos(rotSpeed);
	return (1);
}

static void		init_coordenate(t_data *player, int dirX, int dirY, double planeX, double planeY)
{
	player->dirX = dirX;
	player->dirY = dirY;
	player->planeX = planeX;
	player->planeY = planeY;
}

void			get_coordenate(t_data *player, char c)
{
	if (c == 'N')
		init_coordenate(player, -1, 0, 0, 0.66);
	else if (c == 'S')
		init_coordenate(player, 1, 0, 0, -0.66);
	else if (c == 'W')
		init_coordenate(player, 0, -1, -0.66, 0);
	else if (c == 'E')
		init_coordenate(player, 0, 1, 0.66, 0);
}
