/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 14:19:54 by pcuadrad          #+#    #+#             */
/*   Updated: 2020/01/10 14:13:28 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void		get_hit_aux(t_data *player)
{
	player->ray.hit = 1;
	if (control_life_enemy(player, (int)player->ray.mapx,
		(int)player->ray.mapy))
	{
		change_sprite(player, (int)player->ray.mapx, (int)player->ray.mapy);
		player->map.tab_map[player->ray.mapx][player->ray.mapy] = 0;
	}
}

static void		get_hit(t_data *player)
{
	player->ray.hit = 0;
	while (player->ray.hit == 0)
	{
		if (player->ray.sidedistx < player->ray.sidedisty)
		{
			player->ray.sidedistx += player->ray.deltadistx;
			player->ray.mapx += player->ray.stepx;
		}
		else
		{
			player->ray.sidedisty += player->ray.deltadisty;
			player->ray.mapy += player->ray.stepy;
		}
		if (player->map.tab_map[player->ray.mapx][player->ray.mapy] == 1)
			player->ray.hit = 1;
		else if (player->map.tab_map[player->ray.mapx][player->ray.mapy] == 3)
			get_hit_aux(player);
	}
}

static void		get_step_side(int x, t_data *player)
{
	player->ray.camerax = (2 * x) / (double)player->map.width - 1;
	player->ray.raydirx = player->dirx + player->planex * player->ray.camerax;
	player->ray.raydiry = player->diry + player->planey * player->ray.camerax;
	player->ray.mapx = (int)player->posx;
	player->ray.mapy = (int)player->posy;
	player->ray.deltadistx = sqrt(1 + ((ft_pow(player->ray.raydiry)) /
		(ft_pow(player->ray.raydirx))));
	player->ray.deltadisty = sqrt(1 + ((ft_pow(player->ray.raydirx)) /
		(ft_pow(player->ray.raydiry))));
	player->ray.stepx = (player->ray.raydirx < 0) ? -1 : 1;
	if (player->ray.raydirx < 0)
		player->ray.sidedistx = (player->posx - player->ray.mapx) *
								player->ray.deltadistx;
	else
		player->ray.sidedistx = (player->ray.mapx + 1.0 - player->posx) *
								player->ray.deltadistx;
	player->ray.stepy = (player->ray.raydiry < 0) ? -1 : 1;
	if (player->ray.raydiry < 0)
		player->ray.sidedisty = (player->posy - player->ray.mapy) *
								player->ray.deltadisty;
	else
		player->ray.sidedisty = (player->ray.mapy + 1.0 - player->posy) *
								player->ray.deltadisty;
}

int				shot(t_data *player)
{
	int		x;

	x = player->keys.x_begin - 1;
	player->ray.hit = 0;
	while (++x < player->keys.x_end && player->ray.hit == 0)
	{
		get_step_side(x, player);
		get_hit(player);
	}
	return (1);
}
