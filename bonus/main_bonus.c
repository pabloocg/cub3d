/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 17:54:46 by pcuadrad          #+#    #+#             */
/*   Updated: 2020/01/09 20:00:29 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int			init_render(t_data *player)
{
	if (!(player->mlx_win = mlx_new_window(player->mlx_ptr, player->map.width,
		player->map.screen_height, "CUB3D")))
		return (0);
	if (!(player->depth = (double*)malloc(sizeof(double) * player->map.width)))
		return (0);
	if (!(player->img.id = mlx_new_image(player->mlx_ptr, player->map.width,
		player->map.screen_height)))
		return (0);
	player->img.image = (int*)mlx_get_data_addr(player->img.id,
		&player->img.data, &player->img.size_line, &player->img.endian);
	srand(time(0));
	render(player);
	update_screen(player);
	return (1);
}

void		init_game(int argc, char *argv[], int lifes)
{
	t_data  *player;
	int		num_sprites;

	if ((num_sprites = isvalid(argv)) == -1)
		ft_exit(5);
	if (!(player = init_player(argv, argc, num_sprites, lifes)))
		ft_exit(5);
	if (!(init_render(player)))
		exit_program(player);
	mlx_hook(player->mlx_win, 17, 0, &exit_program, player);
	mlx_hook(player->mlx_win, 2, 0, &hook_key_press, player);
	mlx_hook(player->mlx_win, 3, 0, &hook_key_release, player);
	mlx_loop_hook(player->mlx_ptr, &hook_key_close, player);
	mlx_loop(player->mlx_ptr);
}

int			main(int argc, char *argv[])
{
	if ((argc < 2 || argc > 3) || (!ft_strcmp(argv[1], "--save")))
		ft_exit(3);
	init_game(argc, argv, 6);
    return (EXIT_SUCCESS);
}
