/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 12:05:26 by pcuadrad          #+#    #+#             */
/*   Updated: 2020/01/10 11:18:36 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int				up_down_player(t_data *player, double movespeed, double dirx,
				double diry)
{
	if (player->map.tab_map[(int)(player->posx + dirx * 1)][(int)player->posy]
		== 6)
		control_bullets(player, dirx, 1);
	if (player->map.tab_map[(int)player->posx][(int)(player->posy + diry * 1)]
		== 6)
		control_bullets(player, diry, 0);
	if (player->map.tab_map[(int)(player->posx + dirx * 1)][(int)player->posy]
		== 5)
		control_items(player, dirx, 1);
	if (player->map.tab_map[(int)player->posx][(int)(player->posy + diry * 1)]
		== 5)
		control_items(player, diry, 0);
	if (player->map.tab_map[(int)(player->posx + dirx * 1)][(int)player->posy]
		== 4)
		control_hp(player, dirx, 1);
	if (player->map.tab_map[(int)player->posx][(int)(player->posy + diry * 1)]
		== 4)
		control_hp(player, diry, 0);
	if (player->map.tab_map[(int)(player->posx + dirx * 1)][(int)player->posy]
		== 0)
		player->posx += dirx * movespeed;
	if (player->map.tab_map[(int)player->posx][(int)(player->posy + diry * 1)]
		== 0)
		player->posy += diry * movespeed;
	return (1);
}

int				left_rigth_player(t_data *player, double movespeed,
				double planex, double planey)
{
	if (player->map.tab_map[(int)(player->posx + planex * 1)][(int)player->posy]
		== 6)
		control_bullets(player, planex, 1);
	if (player->map.tab_map[(int)player->posx][(int)(player->posy + planey * 1)]
		== 6)
		control_bullets(player, planey, 0);
	if (player->map.tab_map[(int)(player->posx + planex * 1)][(int)player->posy]
		== 5)
		control_items(player, planex, 1);
	if (player->map.tab_map[(int)player->posx][(int)(player->posy + planey * 1)]
		== 5)
		control_items(player, planey, 0);
	if (player->map.tab_map[(int)(player->posx + planex * 1)][(int)player->posy]
		== 4)
		control_hp(player, planex, 1);
	if (player->map.tab_map[(int)player->posx][(int)(player->posy + planey * 1)]
		== 4)
		control_hp(player, planey, 0);
	if (player->map.tab_map[(int)(player->posx + planex * 1)][(int)player->posy]
		== 0)
		player->posx += planex * movespeed;
	if (player->map.tab_map[(int)player->posx][(int)(player->posy + planey * 1)]
		== 0)
		player->posy += planey * movespeed;
	return (1);
}

int				rotate_player(t_data *player, double rotspeed)
{
	double olddirx;
	double oldplanex;

	olddirx = player->dirx;
	player->dirx = player->dirx * cos(rotspeed) - player->diry * sin(rotspeed);
	player->diry = olddirx * sin(rotspeed) + player->diry * cos(rotspeed);
	oldplanex = player->planex;
	player->planex = player->planex * cos(rotspeed) - player->planey *
	sin(rotspeed);
	player->planey = oldplanex * sin(rotspeed) + player->planey * cos(rotspeed);
	return (1);
}

static void		init_coordenate(t_data *player, double planex, double planey)
{
	player->planex = planex;
	player->planey = planey;
}

void			get_coordenate(t_data *player, char c)
{
	if (c == 'N')
	{
		player->dirx = -1;
		player->diry = 0;
		init_coordenate(player, 0, 0.66);
	}
	else if (c == 'S')
	{
		player->dirx = 1;
		player->diry = 0;
		init_coordenate(player, 0, -0.66);
	}
	else if (c == 'W')
	{
		player->dirx = 0;
		player->diry = -1;
		init_coordenate(player, -0.66, 0);
	}
	else if (c == 'E')
	{
		player->dirx = 0;
		player->diry = 1;
		init_coordenate(player, 0.66, 0);
	}
}
