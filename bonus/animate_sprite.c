/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 19:00:46 by pcuadrad          #+#    #+#             */
/*   Updated: 2020/01/09 18:49:35 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void		move_enemy(int side, sprite_t *sprite, t_data *player)
{
	double	move_speed;

	move_speed = 0.1;
	player->map.tab_map[(int)sprite->posX][(int)sprite->posY] = 0;
	if (side == 0)
	{
		if(player->map.tab_map[(int)(sprite->posX + 1)][(int)sprite->posY] == 0)
			sprite->posX += move_speed * 1;
		if(player->map.tab_map[(int)sprite->posX][(int)(sprite->posY + 1)] == 0)
			sprite->posY += move_speed * 1;
	}
	else if (side == 1)
	{
		if(player->map.tab_map[(int)(sprite->posX - 1)][(int)sprite->posY] == 0)
			sprite->posX -= move_speed * 1;
		if(player->map.tab_map[(int)sprite->posX][(int)(sprite->posY - 1)] == 0)
			sprite->posY -= move_speed * 1;	
	}
	player->map.tab_map[(int)sprite->posX][(int)sprite->posY] = 3;
}

void		animate_sprite(t_data *player)
{
	int     i;

	i = -1;
	while (++i < player->num_sprites)
	{
		if (player->sprite[i].n_text == 1)
			if ((rand() % 20) < 5)
				move_enemy(rand() % 2, &player->sprite[i], player);
	}
}