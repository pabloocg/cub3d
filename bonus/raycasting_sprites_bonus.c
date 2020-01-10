/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_sprites_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:58:48 by pcuadrad          #+#    #+#             */
/*   Updated: 2020/01/10 11:36:46 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	sort_sprites(int *order_sprite, double *distance_sprite,
	int num_sprites)
{
	int		i;
	int		j;
	int		tmpdis;
	int		tmporder;

	i = -1;
	while ((++i < num_sprites - 1) && (j = -1))
		while (++j < num_sprites - 1)
		{
			if (distance_sprite[j] < distance_sprite[j + 1])
			{
				tmpdis = distance_sprite[j + 1];
				distance_sprite[j + 1] = distance_sprite[j];
				distance_sprite[j] = tmpdis;
				tmporder = order_sprite[j + 1];
				order_sprite[j + 1] = order_sprite[j];
				order_sprite[j] = tmporder;
			}
		}
}

int			get_distance_sprites(t_data *player)
{
	int	i;

	if (!(player->ray_sprite.spriteorder = (int*)malloc(sizeof(int) *
		player->num_sprites)))
		return (0);
	if (!(player->ray_sprite.spritedistance = (double*)malloc(sizeof(double) *
		player->num_sprites)))
		return (0);
	i = -1;
	while (++i < player->num_sprites)
	{
		player->ray_sprite.spriteorder[i] = i;
		player->ray_sprite.spritedistance[i] = (ft_pow((player->posx - player->
		sprite[i].posx)) + ft_pow((player->posy - player->sprite[i].posy)));
	}
	return (1);
}

static void	get_draw(t_data *player)
{
	player->ray_sprite.spriteheight = abs((int)(player->map.height /
	(player->ray_sprite.transformy))) / VDIV;
	player->ray_sprite.drawstarty = -player->ray_sprite.spriteheight / 2 +
	player->map.height / 2 + player->ray_sprite.vmovescreen;
	player->ray_sprite.drawstarty = (player->ray_sprite.drawstarty < 0) ? 0 :
	player->ray_sprite.drawstarty;
	player->ray_sprite.drawendy = player->ray_sprite.spriteheight / 2 + player->
	map.height / 2 + player->ray_sprite.vmovescreen;
	player->ray_sprite.drawendy = (player->ray_sprite.drawendy >= player->
	map.height) ? player->map.height - 1 : player->ray_sprite.drawendy;
	player->ray_sprite.spritewidth = abs((int)(player->map.width / (player->
	ray_sprite.transformy))) / VDIV;
	player->ray_sprite.drawstartx = -player->ray_sprite.spritewidth / 2 +
	player->ray_sprite.spritescreenx;
	player->ray_sprite.drawstartx = (player->ray_sprite.drawstartx < 0) ? 0 :
	player->ray_sprite.drawstartx;
	player->ray_sprite.drawendx = player->ray_sprite.spritewidth / 2 + player->
	ray_sprite.spritescreenx;
	player->ray_sprite.drawendx = (player->ray_sprite.drawendx >= player->
	map.width) ? player->map.width - 1 : player->ray_sprite.drawendx;
}

static void	render_sprite_aux(t_data *player)
{
	player->ray_sprite.transformy = player->ray_sprite.invdet *
	(-player->planey * player->ray_sprite.spritex + player->planex *
	player->ray_sprite.spritey);
	player->ray_sprite.spritescreenx = (int)((player->map.width / 2)
	* (1 + player->ray_sprite.transformx / player->ray_sprite.transformy));
	player->ray_sprite.vmovescreen = (int)(VMOVE / player->ray_sprite.
	transformy);
}

void		render_sprite(t_data *player)
{
	int		i;

	if (!(get_distance_sprites(player)))
		exit_program(player);
	sort_sprites(player->ray_sprite.spriteorder, player->ray_sprite.
	spritedistance, player->num_sprites);
	i = -1;
	while (++i < player->num_sprites)
	{
		player->ray_sprite.spritex = player->sprite[player->ray_sprite.
		spriteorder[i]].posx - player->posx;
		player->ray_sprite.spritey = player->sprite[player->ray_sprite.
		spriteorder[i]].posy - player->posy;
		player->ray_sprite.invdet = 1. / ((player->planex * player->diry)
		- (player->dirx * player->planey));
		player->ray_sprite.transformx = player->ray_sprite.invdet *
		(player->diry * player->ray_sprite.spritex - player->dirx *
		player->ray_sprite.spritey);
		render_sprite_aux(player);
		get_draw(player);
		print_sprite(player, i);
	}
	free(player->ray_sprite.spriteorder);
	free(player->ray_sprite.spritedistance);
}
