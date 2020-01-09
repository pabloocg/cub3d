/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:14:18 by pcuadrad          #+#    #+#             */
/*   Updated: 2020/01/09 13:14:56 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static	void	get_wall_hit(t_data *player)
{
	if (player->ray.side == 1)
		player->ray.wallhit_x = player->posx + ((player->ray.mapy - player->posy
		+ (1 - player->ray.stepy) / 2) / player->ray.raydiry) *
		player->ray.raydirx;
	else
		player->ray.wallhit_x = player->posy + ((player->ray.mapx - player->posx
		+ (1 - player->ray.stepx) / 2) / player->ray.raydirx) *
		player->ray.raydiry;
	player->ray.wallhit_x -= floor(player->ray.wallhit_x);
}

static void		get_distance(t_data *player, int x)
{
	if (player->ray.side == 0)
		player->ray.perpwalldist = fabs((player->ray.mapx - player->posx +
			(1 - player->ray.stepx) / 2.) / player->ray.raydirx);
	else
		player->ray.perpwalldist = fabs((player->ray.mapy - player->posy +
			(1 - player->ray.stepy) / 2.) / player->ray.raydiry);
	player->depth[x] = fabs(player->ray.perpwalldist);
	player->ray.lineheight = (int)(player->map.height /
	player->ray.perpwalldist);
	player->ray.drawstart = (-player->ray.lineheight / 2) +
	(player->map.height / 2);
	player->ray.drawstart = (player->ray.drawstart < 0) ?
	0 : player->ray.drawstart;
	player->ray.drawend = (player->ray.lineheight / 2) +
		(player->map.height / 2);
	player->ray.drawend = (player->ray.drawend >= player->map.height) ?
	player->map.height - 1 : player->ray.drawend;
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
			player->ray.side = 0;
		}
		else
		{
			player->ray.sidedisty += player->ray.deltadisty;
			player->ray.mapy += player->ray.stepy;
			player->ray.side = 1;
		}
		if (player->map.tab_map[player->ray.mapx][player->ray.mapy] == 1)
			player->ray.hit = 1;
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

void			render(t_data *player)
{
	int		x;

	ft_bzero(player->img.image, player->map.width * player->map.height);
	x = -1;
	while (++x < player->map.width)
	{
		get_step_side(x, player);
		get_hit(player);
		get_distance(player, x);
		get_wall_hit(player);
		print_column(player, player->ray.drawend, x,
			get_texture(player));
	}
	render_sprite(player);
}
