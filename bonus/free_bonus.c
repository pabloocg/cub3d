/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 16:11:39 by pcuadrad          #+#    #+#             */
/*   Updated: 2019/12/21 16:11:39 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	free_map(data_t *player)
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
		free(player->map.tab_map);
}

void	free_all(data_t *player)
{
	if (player)
		free_map(player);
	if (player->depth)
		free(player->depth);
	if (player->textur.sprite)
		free(player->textur.sprite);
	if (player->sprite)
		free(player->sprite);
	mlx_destroy_image(player->mlx_ptr, player->img.id);
	mlx_destroy_window(player->mlx_ptr, player->mlx_win);
	if (player)
		free(player);
}

void	free_path_textures(data_t *player, int control)
{
	if (control == 1)
	{
		free(player->textur.north_text.path);
		free(player->textur.south_text.path);
		free(player->textur.east_text.path);
		free(player->textur.weast_text.path);
		free(player->textur.sprite[0].path);
	}
	else if (control == 2)
	{
		free(player->textur.south_text.path);
		free(player->textur.east_text.path);
		free(player->textur.weast_text.path);
		free(player->textur.sprite[0].path);
	}
	else if (control == 3)
	{
		free(player->textur.east_text.path);
		free(player->textur.weast_text.path);
		free(player->textur.sprite[0].path);
	}
	else if (control == 4)
	{
		free(player->textur.weast_text.path);
		free(player->textur.sprite[0].path);
	}
	else if (control == 5)
		free(player->textur.sprite[0].path);
}
