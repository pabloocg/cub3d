/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_sprites_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:58:48 by pcuadrad          #+#    #+#             */
/*   Updated: 2019/12/31 16:53:53 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	sort_sprites(int *order_sprite, double *distance_sprite, int num_sprites)
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

int			get_distance_sprites(data_t *player)
{
	int	i;

	if (!(player->ray_sprite.spriteOrder = (int*)malloc(sizeof(int) * player->num_sprites)))
		return(0);
	if (!(player->ray_sprite.spriteDistance = (double*)malloc(sizeof(double) * player->num_sprites)))
		return(0);
	i = -1;
	while (++i < player->num_sprites)
	{
		player->ray_sprite.spriteOrder[i] = i;
		player->ray_sprite.spriteDistance[i] = (ft_pow((player->posX - player->sprite[i].posX)) + ft_pow((player->posY - player->sprite[i].posY)));
	}
	return (1);
}

static void	get_draw(data_t *player)
{
	player->ray_sprite.spriteHeight = abs((int)(player->map.height / (player->ray_sprite.transformY))) / vDiv;
	player->ray_sprite.drawStartY = -player->ray_sprite.spriteHeight / 2 + player->map.height / 2 + player->ray_sprite.vMoveScreen;
	player->ray_sprite.drawStartY = (player->ray_sprite.drawStartY < 0) ? 0 : player->ray_sprite.drawStartY;
	player->ray_sprite.drawEndY = player->ray_sprite.spriteHeight / 2 + player->map.height / 2 + player->ray_sprite.vMoveScreen;
	player->ray_sprite.drawEndY = (player->ray_sprite.drawEndY >= player->map.height) ? player->map.height - 1 : player->ray_sprite.drawEndY;
	player->ray_sprite.spriteWidth = abs((int)(player->map.width / (player->ray_sprite.transformY))) / uDiv;
	player->ray_sprite.drawStartX = -player->ray_sprite.spriteWidth / 2 + player->ray_sprite.spriteScreenX;
	player->ray_sprite.drawStartX = (player->ray_sprite.drawStartX < 0) ? 0 : player->ray_sprite.drawStartX;
	player->ray_sprite.drawEndX = player->ray_sprite.spriteWidth / 2 + player->ray_sprite.spriteScreenX;
	player->ray_sprite.drawEndX = (player->ray_sprite.drawEndX >= player->map.width) ? player->map.width - 1 : player->ray_sprite.drawEndX;
}

void		print_sprite(data_t *player, int i)
{
	int				stripe;
	int				texX;
	int				texY;
	unsigned int	color;
	int				y;

	stripe = player->ray_sprite.drawStartX - 1;
	while (++stripe < player->ray_sprite.drawEndX && stripe < player->map.width)
	{
		texX = (int)(256 * (((int)(stripe) - (-player->ray_sprite.spriteWidth / 2 + player->ray_sprite.spriteScreenX))) * player->textur.sprite[player->sprite[player->ray_sprite.spriteOrder[i]].n_text].w / player->ray_sprite.spriteWidth) / 256;
		if(player->ray_sprite.transformY > 0 && player->ray_sprite.transformY < player->depth[(int)stripe])
		{
			y = player->ray_sprite.drawStartY - 1;
			while (++y < player->ray_sprite.drawEndY && y < player->map.height)
			{
				player->ray_sprite.print_y = ((int)(y - player->ray_sprite.vMoveScreen) * 256.) - (player->map.height * 128.) + (player->ray_sprite.spriteHeight * 128.);
				texY = ((player->ray_sprite.print_y * player->textur.sprite[player->sprite[player->ray_sprite.spriteOrder[i]].n_text].h) / player->ray_sprite.spriteHeight) / 256.;
				color = player->textur.sprite[player->sprite[player->ray_sprite.spriteOrder[i]].n_text].image[(player->textur.sprite[player->sprite[player->ray_sprite.spriteOrder[i]].n_text].w * texY) + texX];
				if(((player->sprite[player->ray_sprite.spriteOrder[i]].n_text != 1 && color != 0) &&
					(player->sprite[player->ray_sprite.spriteOrder[i]].n_text != 3 && color != 0)) ||
					(player->sprite[player->ray_sprite.spriteOrder[i]].n_text == 1 && color != 9961608) ||
						(player->sprite[player->ray_sprite.spriteOrder[i]].n_text == 3 && color != 9961608))
					player->img.image[(y * player->map.width) + stripe] = color;
			}
		}
	}
}

void		render_sprite(data_t *player)
{
	int		i;
	
	if (!(get_distance_sprites(player)))
		;
	sort_sprites(player->ray_sprite.spriteOrder, player->ray_sprite.spriteDistance, player->num_sprites);
	i = -1;
	while (++i < player->num_sprites)
	{
		player->ray_sprite.spriteX = player->sprite[player->ray_sprite.spriteOrder[i]].posX - player->posX;
		player->ray_sprite.spriteY = player->sprite[player->ray_sprite.spriteOrder[i]].posY - player->posY;
		player->ray_sprite.invDet = 1. / ((player->planeX * player->dirY) - (player->dirX * player->planeY));
		player->ray_sprite.transformX = player->ray_sprite.invDet * (player->dirY * player->ray_sprite.spriteX - player->dirX * player->ray_sprite.spriteY);
		player->ray_sprite.transformY = player->ray_sprite.invDet * (-player->planeY * player->ray_sprite.spriteX + player->planeX * player->ray_sprite.spriteY);
		player->ray_sprite.spriteScreenX = (int)((player->map.width / 2) * (1 + player->ray_sprite.transformX / player->ray_sprite.transformY));
		player->ray_sprite.vMoveScreen = (int)(vMove / player->ray_sprite.transformY);
		get_draw(player);
		print_sprite(player, i);
	}
	free(player->ray_sprite.spriteOrder);
	free(player->ray_sprite.spriteDistance);
}
