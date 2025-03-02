/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 19:10:03 by pcuadrad          #+#    #+#             */
/*   Updated: 2020/01/10 12:54:07 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void		enemy_attack(t_data *player)
{
	if ((rand() % 11) < 5)
		player->hp_current -= (1.5 * (rand() % player->ray.seeprite));
	control_life(player);
}

static void	buffer_bullets(t_data *player)
{
	char		*buffer_bullets;
	const char	*current_bullets;
	const char	*join_bullets;

	current_bullets = ft_itoa(player->bullet_current);
	join_bullets = ft_strjoin(current_bullets, " / 20");
	free((void*)current_bullets);
	buffer_bullets = ft_strjoin("AMMO: ", join_bullets);
	free((void*)join_bullets);
	mlx_string_put(player->mlx_ptr, player->mlx_win, (player->map.width /
	10), (player->map.height + ((player->map.screen_height -
	player->map.height) / 3)), create_color(255, 255, 255), buffer_bullets);
	free((void*)buffer_bullets);
}

static void	buffer_items(t_data *player)
{
	char		*buffer_items;
	const char	*current_items;
	const char	*join_items;

	current_items = ft_itoa(player->items_current);
	join_items = ft_strjoin(current_items, " / 5");
	free((void*)current_items);
	buffer_items = ft_strjoin("Items Collected: ", join_items);
	free((void*)join_items);
	mlx_string_put(player->mlx_ptr, player->mlx_win, (player->map.width /
	10), (player->map.height + ((player->map.screen_height -
	player->map.height) / 2)), create_color(255, 255, 255), buffer_items);
	free((void*)buffer_items);
}

void		update_screen(t_data *player)
{
	mlx_put_image_to_window(player->mlx_ptr, player->mlx_win, player->img.id,
	0, 0);
	mlx_string_put(player->mlx_ptr, player->mlx_win, (player->map.width /
	2), (player->map.height + ((player->map.screen_height -
	player->map.height) / 2)), create_color(255, 255, 255), "HP: ");
	buffer_bullets(player);
	buffer_items(player);
}
