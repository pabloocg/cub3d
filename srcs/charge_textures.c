/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charge_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 12:48:44 by pcuadrad          #+#    #+#             */
/*   Updated: 2019/12/26 17:19:07 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

text_t	get_texture(data_t *player)
{
	if (player->map.tab_map[player->ray.mapX][player->ray.mapY] == 1 &&
		player->ray.side && player->ray.stepY >= 0)
		return (player->textur.east_text);
	else if (player->map.tab_map[player->ray.mapX][player->ray.mapY] == 1 &&
		player->ray.side && player->ray.stepY < 0)
		return (player->textur.weast_text);
	else if (player->map.tab_map[player->ray.mapX][player->ray.mapY] == 1 &&
		!player->ray.side && player->ray.stepX >= 0)
		return (player->textur.south_text);
	else if (player->map.tab_map[player->ray.mapX][player->ray.mapY] == 1 &&
		!player->ray.side && player->ray.stepX < 0)
		return (player->textur.north_text);
	else
		return (player->textur.sprite);
}

static int	charge_textures(data_t *player, text_t *texture)
{
	if (texture->path)
		if (!(texture->id = mlx_xpm_file_to_image(player->mlx_ptr, texture->path, &texture->w, &texture->h)))
			return (0);
	if (!(texture->image = (int*)mlx_get_data_addr(texture->id, &texture->data, &texture->size_line, &texture->endian)))
		return (0);
	free(texture->path);
	return (1);
}

void		charge_textures_main(data_t *player)
{
	if (!(charge_textures(player, &player->textur.north_text)))
	{
		free_path_textures(player, 1);
		ft_exit(4);
	}
	if (!(charge_textures(player, &player->textur.south_text)))
	{
		free_path_textures(player, 2);
		ft_exit(4);
	}
	if (!(charge_textures(player, &player->textur.east_text)))
	{
		free_path_textures(player, 3);
		ft_exit(4);
	}
	if (!(charge_textures(player, &player->textur.weast_text)))
	{
		free_path_textures(player, 4);
		ft_exit(4);
	}
	if (!(charge_textures(player, &player->textur.sprite)))
	{
		free_path_textures(player, 5);
		ft_exit(4);
	}
}