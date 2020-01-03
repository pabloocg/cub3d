/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 20:13:36 by pablo             #+#    #+#             */
/*   Updated: 2019/12/26 19:50:24 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		hook_key_press(int key, data_t *player)
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

int		hook_key_release(int key, data_t *player)
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

int     hook_key_close(data_t *player)
{
	double	rotSpeed;
	double	moveSpeed;
	int		update;

	rotSpeed = 0.05;
	moveSpeed = 0.15;
	update = 0;
	if (player->keys.key_a == 1)
		update = left_rigth_player(player, moveSpeed, -player->planeX, -player->planeY);
	if (player->keys.key_w == 1)
		update = up_down_player(player, moveSpeed, player->dirX, player->dirY);
	if (player->keys.key_s == 1)
		update = up_down_player(player, moveSpeed, -player->dirX, -player->dirY);
	if (player->keys.key_d == 1)
		update = left_rigth_player(player, moveSpeed, player->planeX, player->planeY);
	if (player->keys.key_iz == 1)
		update = rotate_player(player, rotSpeed);
	if (player->keys.key_dir == 1)
		update = rotate_player(player, -rotSpeed);
	if (update)
	{
		render(player);
		mlx_put_image_to_window(player->mlx_ptr, player->mlx_win, player->img.id,
		0, 0);
	}
	return (0);
}
