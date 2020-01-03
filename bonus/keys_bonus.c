/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 20:13:36 by pablo             #+#    #+#             */
/*   Updated: 2020/01/02 14:51:17 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int		hook_key_press(int key, data_t *player)
{
	int		argc;
	char	*argv[2];
	int		lifes;

	if (KEY_ESC == key)
		exit_program(player);
	if (KEY_A == key && player->init_game == 0)
		player->keys.key_a = 1;
	if ((KEY_W == key || KEY_ARROW_UP == key) && player->init_game == 0)
		player->keys.key_w = 1;
	if ((KEY_S == key || KEY_ARROW_DOWN == key) && player->init_game == 0)
		player->keys.key_s = 1;
	if (KEY_D == key && player->init_game == 0)
		player->keys.key_d = 1;
	if (KEY_ARROW_LEFT == key && player->init_game == 0)
		player->keys.key_iz = 1;
	if (KEY_ARROW_RIGHT == key && player->init_game == 0)
		player->keys.key_dir = 1;
	if (KEY_SPACE == key && player->init_game == 0)
	{
		if ((player->bullet_current -= 1) > 0)
		{
			play_shot(player);
			player->keys.key_space = 1;
		}
		else if (player->bullet_current <= 0)
			player->bullet_current = 0;
	}
	if (KEY_ENTER == key && player->init_game == 1)
	{
		argc = player->argc;
		argv[0] = player->argv[0];
		argv[1] = player->argv[1];
		lifes = player->lifes -= 1;
		if (lifes > 0)
		{
			free_all(player);
			init_game(argc, argv, lifes);
		}
		else
			exit_program(player);
	}
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
	if (KEY_SPACE == key)
		player->keys.key_space = 0;
	return (0);
}

int     hook_key_close(data_t *player)
{
	double	rotSpeed;
	double	moveSpeed;

	rotSpeed = 0.03;
	moveSpeed = 0.1;
	if (player->keys.key_a == 1)
		left_rigth_player(player, moveSpeed, -player->planeX, -player->planeY);
	if (player->keys.key_w == 1)
		up_down_player(player, moveSpeed, player->dirX, player->dirY);
	if (player->keys.key_s == 1)
		up_down_player(player, moveSpeed, -player->dirX, -player->dirY);
	if (player->keys.key_d == 1)
		left_rigth_player(player, moveSpeed, player->planeX, player->planeY);
	if (player->keys.key_iz == 1)
		rotate_player(player, rotSpeed);
	if (player->keys.key_dir == 1)
		rotate_player(player, -rotSpeed);
	if (player->keys.key_space == 1)
		shot(player);
	render(player);
	update_screen(player);
	return (0);
}
