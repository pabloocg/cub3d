/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fuck_norminnete.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 10:49:27 by pcuadrad          #+#    #+#             */
/*   Updated: 2020/01/10 12:56:23 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

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

void			control_bullets(t_data *player, double dir, int side)
{
	if (side == 1)
	{
		if ((player->bullet_current += 5) > player->bullet_max)
			player->bullet_current = player->bullet_max;
		delete_sprite(player, (int)(player->posx + dir * 1), (int)player->posy);
		player->map.tab_map[(int)(player->posx + dir * 1)][(int)player->posy] =
			0;
	}
	else
	{
		if ((player->bullet_current += 5) > player->bullet_max)
			player->bullet_current = player->bullet_max;
		delete_sprite(player, (int)player->posx, (int)(player->posy + dir * 1));
		player->map.tab_map[(int)player->posx][(int)(player->posy + dir * 1)] =
			0;
	}
}

void			control_items(t_data *player, double dir, int side)
{
	if (side == 1)
	{
		player->items_current += 1;
		delete_sprite(player, (int)(player->posx + dir * 1), (int)player->posy);
		player->map.tab_map[(int)(player->posx + dir * 1)][(int)player->posy] =
			0;
	}
	else
	{
		player->items_current += 1;
		delete_sprite(player, (int)player->posx, (int)(player->posy + dir * 1));
		player->map.tab_map[(int)player->posx][(int)(player->posy + dir * 1)] =
			0;
	}
}

void			control_hp(t_data *player, double dir, int side)
{
	if (side == 1)
	{
		player->hp_current += 30.;
		control_life(player);
		delete_sprite(player, (int)(player->posx + dir * 1), (int)player->posy);
		player->map.tab_map[(int)(player->posx + dir * 1)][(int)player->posy] =
			0;
	}
	else
	{
		player->hp_current += 30.;
		control_life(player);
		delete_sprite(player, (int)player->posx, (int)(player->posy + dir * 1));
		player->map.tab_map[(int)player->posx][(int)(player->posy + dir * 1)] =
			0;
	}
}

void			isfirst_or_last_line(char *line, t_data *player)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != ' ')
		{
			free(line);
			free(player->map.tab_map);
			free_path_textures(player, 1);
			free(player->sprite);
			free(player);
			ft_exit(2);
		}
		i++;
	}
}
