/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charge_textures_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 12:48:44 by pcuadrad          #+#    #+#             */
/*   Updated: 2020/01/10 12:16:45 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

t_text		get_texture(t_data *player)
{
	if (player->map.tab_map[player->ray.mapx][player->ray.mapy] == 1 &&
		player->ray.side && player->ray.stepy >= 0)
		return (player->textur.east_text);
	else if (player->map.tab_map[player->ray.mapx][player->ray.mapy] == 1 &&
		player->ray.side && player->ray.stepy < 0)
		return (player->textur.weast_text);
	else if (player->map.tab_map[player->ray.mapx][player->ray.mapy] == 1 &&
		!player->ray.side && player->ray.stepx >= 0)
		return (player->textur.south_text);
	else if (player->map.tab_map[player->ray.mapx][player->ray.mapy] == 1 &&
		!player->ray.side && player->ray.stepx < 0)
		return (player->textur.north_text);
	else
		return (player->textur.sprite[0]);
}

int			charge_textures(t_data *player, t_text *texture)
{
	if (texture->path)
		if (!(texture->id = mlx_xpm_file_to_image(player->mlx_ptr,
			texture->path, &texture->w, &texture->h)))
			return (0);
	if (!(texture->image = (int*)mlx_get_data_addr(texture->id, &texture->data,
		&texture->size_line, &texture->endian)))
		return (0);
	free(texture->path);
	return (1);
}

void		charge_textures_sprites(t_data *player)
{
	if (!(charge_textures(player, &player->textur.sprite[0])))
		ft_exit(4);
	if (!(charge_textures(player, &player->textur.sprite[1])))
		ft_exit(4);
	if (!(charge_textures(player, &player->textur.sprite[2])))
		ft_exit(4);
	if (!(charge_textures(player, &player->textur.sprite[3])))
		ft_exit(4);
	if (!(charge_textures(player, &player->textur.sprite[4])))
		ft_exit(4);
	if (!(charge_textures(player, &player->textur.sprite[5])))
		ft_exit(4);
}

void		charge_textures_main(t_data *player)
{
	if (!(charge_textures(player, &player->textur.north_text)))
		ft_exit(4);
	if (!(charge_textures(player, &player->textur.south_text)))
		ft_exit(4);
	if (!(charge_textures(player, &player->textur.east_text)))
		ft_exit(4);
	if (!(charge_textures(player, &player->textur.weast_text)))
		ft_exit(4);
	if (!(charge_textures(player, &player->textur.ceilling)))
		ft_exit(4);
	if (!(charge_textures(player, &player->textur.floor)))
		ft_exit(4);
	if (!(charge_textures(player, &player->textur.layaout)))
		ft_exit(4);
	if (!(charge_textures(player, &player->textur.gun)))
		ft_exit(4);
	if (!(charge_textures(player, &player->textur.gunshot)))
		ft_exit(4);
	charge_textures_sprites(player);
}
