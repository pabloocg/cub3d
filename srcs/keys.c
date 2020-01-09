/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 20:13:36 by pablo             #+#    #+#             */
/*   Updated: 2020/01/09 12:58:09 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		hook_key_press(int key, t_data *player)
{
	if (KEY_ESC == key)
		exit_program(player);
	if (KEY_A == key)
		player->keys.key_a = 1;
	if (KEY_W == key || KEY_ARROW_UP == key)
		player->keys.key_w = 1;
	if (KEY_S == key || KEY_ARROW_DOWN == key)
		player->keys.key_s = 1;
	if (KEY_D == key)
		player->keys.key_d = 1;
	if (KEY_ARROW_LEFT == key)
		player->keys.key_iz = 1;
	if (KEY_ARROW_RIGHT == key)
		player->keys.key_dir = 1;
	return (0);
}

int		hook_key_release(int key, t_data *player)
{
	if (KEY_A == key)
		player->keys.key_a = 0;
	if (KEY_W == key || KEY_ARROW_UP == key)
		player->keys.key_w = 0;
	if (KEY_S == key || KEY_ARROW_DOWN == key)
		player->keys.key_s = 0;
	if (KEY_D == key)
		player->keys.key_d = 0;
	if (KEY_ARROW_LEFT == key)
		player->keys.key_iz = 0;
	if (KEY_ARROW_RIGHT == key)
		player->keys.key_dir = 0;
	return (0);
}

int		hook_key_close(t_data *player)
{
	double	rotspeed;
	double	movespeed;

	rotspeed = 0.05;
	movespeed = 0.15;
	if (player->keys.key_a == 1)
		left_rigth_player(player, movespeed, -player->planex,
		-player->planey);
	if (player->keys.key_w == 1)
		up_down_player(player, movespeed, player->dirx, player->diry);
	if (player->keys.key_s == 1)
		up_down_player(player, movespeed, -player->dirx, -player->diry);
	if (player->keys.key_d == 1)
		left_rigth_player(player, movespeed, player->planex, player->planey);
	if (player->keys.key_iz == 1)
		rotate_player(player, rotspeed);
	if (player->keys.key_dir == 1)
		rotate_player(player, -rotspeed);
	render(player);
	mlx_put_image_to_window(player->mlx_ptr, player->mlx_win, player->img.id,
		0, 0);
	return (0);
}
