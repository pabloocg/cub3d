/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 12:05:26 by pcuadrad          #+#    #+#             */
/*   Updated: 2020/01/09 13:34:18 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int				up_down_player(t_data *player, double movespeed, double dirx,
	double diry)
{
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
