/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 20:13:36 by pablo             #+#    #+#             */
/*   Updated: 2020/01/10 14:13:35 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	hook_key_press_aux(t_data *player)
{
	if ((player->bullet_current -= 1) > 0)
		player->keys.key_space = 1;
	else if (player->bullet_current <= 0)
		player->bullet_current = 0;
}

static void	hook_key_press_game_over(t_data *player)
{
	int		argc;
	char	*argv[2];

	argc = player->argc;
	argv[0] = player->argv[0];
	argv[1] = player->argv[1];
	free_all(player);
	init_game(argc, argv);
}

int			hook_key_press(int key, t_data *player)
{
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
		hook_key_press_aux(player);
	if (KEY_ENTER == key && player->init_game == 1)
		hook_key_press_game_over(player);
	return (0);
}

int			hook_key_release(int key, t_data *player)
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

int			hook_key_close(t_data *player)
{
	double	rotspeed;
	double	movespeed;

	rotspeed = 0.03;
	movespeed = 0.1;
	if (player->keys.key_a == 1)
		left_rigth_player(player, movespeed, -player->planex, -player->planey);
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
	if (player->keys.key_space == 1)
		shot(player);
	render(player);
	update_screen(player);
	return (0);
}
