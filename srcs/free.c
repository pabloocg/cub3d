/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:58:26 by pcuadrad          #+#    #+#             */
/*   Updated: 2020/01/09 12:02:20 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_map(t_data *player)
{
	int		i;

	i = 0;
	while (i < player->map.x_max)
	{
		if (player->map.tab_map[i])
			free(player->map.tab_map[i]);
		i++;
	}
	if (player->map.tab_map)
	{
		free(player->map.tab_map);
		player->map.tab_map = NULL;
	}
}

void	free_all(t_data *player)
{
	if (player)
		free_map(player);
	if (player->depth)
	{
		free(player->depth);
		player->depth = NULL;
	}
	if (player->sprite)
	{
		free(player->sprite);
		player->sprite = NULL;
	}
	if (player)
	{
		free(player);
		player = NULL;
	}
}

void	free_path_textures_2(t_data *player, int control)
{
	if (control == 3)
	{
		free(player->textur.east_text.path);
		free(player->textur.weast_text.path);
		free(player->textur.sprite.path);
	}
	else if (control == 4)
	{
		free(player->textur.weast_text.path);
		free(player->textur.sprite.path);
	}
	else if (control == 5)
		free(player->textur.sprite.path);
}

void	free_path_textures(t_data *player, int control)
{
	if (control == 1)
	{
		free(player->textur.north_text.path);
		free(player->textur.south_text.path);
		free(player->textur.east_text.path);
		free(player->textur.weast_text.path);
		free(player->textur.sprite.path);
	}
	else if (control == 2)
	{
		free(player->textur.south_text.path);
		free(player->textur.east_text.path);
		free(player->textur.weast_text.path);
		free(player->textur.sprite.path);
	}
	else
		free_path_textures_2(player, control);
}
