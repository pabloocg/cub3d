/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 19:10:03 by pcuadrad          #+#    #+#             */
/*   Updated: 2020/01/02 15:09:35 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void        enemy_attack(data_t *player)
{
    if ((rand() % 11) < 5)
		player->hp_current -= (1.5 * (rand() % player->ray.seeprite));
	control_life(player);
}

void		update_screen(data_t *player)
{
	char	*buffer_bullets;
	char	*buffer_items;
	char	*lifes;

	mlx_put_image_to_window(player->mlx_ptr, player->mlx_win, player->img.id,
	0, 0);
	mlx_string_put(player->mlx_ptr, player->mlx_win, (player->map.width /
	2), (player->map.height + ((player->map.screen_height -
	player->map.height) / 2)), create_color(255, 255, 255), "HP: ");
	buffer_bullets = "AMMO: ";
	buffer_bullets = ft_strjoin((const char*)buffer_bullets, (const char*)ft_strjoin((const char*)ft_itoa(player->bullet_current), " / 20"));
	mlx_string_put(player->mlx_ptr, player->mlx_win, (player->map.width /
	4), (player->map.height + ((player->map.screen_height -
	player->map.height) / 2)), create_color(255, 255, 255), buffer_bullets);
	buffer_items = "Items Collect: ";
	buffer_items = ft_strjoin((const char*)buffer_items, (const char*)ft_strjoin((const char*)ft_itoa(player->items_current), " / 5"));
	mlx_string_put(player->mlx_ptr, player->mlx_win, (player->map.width /
	10), (player->map.height + ((player->map.screen_height -
	player->map.height) / 2)), create_color(255, 255, 255), buffer_items);
	lifes = "LIFES: ";
	mlx_string_put(player->mlx_ptr, player->mlx_win, (player->map.width /
	10), (player->map.height + ((player->map.screen_height -
	player->map.height) / 3)), create_color(255, 255, 255), ft_strjoin((const char*)lifes, ft_itoa(player->lifes)));
}