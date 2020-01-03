/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 14:19:54 by pcuadrad          #+#    #+#             */
/*   Updated: 2020/01/02 15:00:48 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static int	control_life_enemy(data_t *player, int posX, int posY)
{
	int		i;

	i = -1;
	while (++i < player->num_sprites)
	{
		if ((int)player->sprite[i].posX == posX && (int)player->sprite[i].posY == posY)
		{
			player->sprite[i].hp -= (rand() % 3) * 10;
			if (player->sprite[i].hp <= 0)
				return (1);
			break ;
		}
	}
	return (0);
}

void		delete_sprite(data_t *player, int posX, int posY)
{
	int			i;
	sprite_t	temp;

	i = -1;
	while (++i < player->num_sprites)
	{
		if ((int)player->sprite[i].posX == posX && (int)player->sprite[i].posY == posY)
		{
			temp = player->sprite[player->num_sprites - 1];
			player->sprite[player->num_sprites - 1] = player->sprite[i];
			player->sprite[i] = temp;
			break ;
		}
	}
	player->num_sprites -= 1;
}

void		change_sprite(data_t *player, int posX, int posY)
{
	int			i;

	i = -1;
	while (++i < player->num_sprites)
		if ((int)player->sprite[i].posX == posX && (int)player->sprite[i].posY == posY)
			player->sprite[i].n_text = 3;
}

static void		get_hit(data_t *player)
{
	player->ray.hit = 0;
	while (player->ray.hit == 0)
	{
		if (player->ray.sideDistX < player->ray.sideDistY)
		{
			player->ray.sideDistX += player->ray.deltaDistX;
			player->ray.mapX += player->ray.stepX;
		}
		else
		{
			player->ray.sideDistY += player->ray.deltaDistY;
			player->ray.mapY += player->ray.stepY;
		}
		if (player->map.tab_map[player->ray.mapX][player->ray.mapY] == 1)
			player->ray.hit = 1;
		else if (player->map.tab_map[player->ray.mapX][player->ray.mapY] == 3)
		{
			player->ray.hit = 1;
			if (control_life_enemy(player, (int)player->ray.mapX, (int)player->ray.mapY))
			{
				change_sprite(player, (int)player->ray.mapX, (int)player->ray.mapY);
				player->map.tab_map[player->ray.mapX][player->ray.mapY] = 0;
			}
		}
	}
}

static void		get_step_side(int x, data_t *player)
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

int         shot(data_t *player)
{
    int     x;

    x = player->keys.x_begin - 1;
	player->ray.hit = 0;
    while (++x < player->keys.x_end && player->ray.hit == 0)
    {
        get_step_side(x, player);
        get_hit(player);
    }
    return (1);
}

void	play_shot(data_t *player)
{
    pid_t		x;
	//static char	kill[17] = "kill -9 ";
 
	x = fork();	
	if (x < 0)
	{
		ft_printf("fork failure\n");
		exit_program(player);
	}   
	else if (x == 0)
		execlp("mpg123", "mpg123", "-q", "sounds/shot.mp3", 0);
}