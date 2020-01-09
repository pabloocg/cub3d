/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 17:54:46 by pcuadrad          #+#    #+#             */
/*   Updated: 2020/01/09 11:57:11 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			init_render(t_data *player)
{
	if (!(player->mlx_win = mlx_new_window(player->mlx_ptr, player->map.width,
		player->map.height, "CUB3D")))
		return (0);
	if (!(player->depth = (double*)malloc(sizeof(double) * player->map.width)))
		return (0);
	if (!(player->img.id = mlx_new_image(player->mlx_ptr, player->map.width,
		player->map.height)))
		return (0);
	player->img.image = (int*)mlx_get_data_addr(player->img.id,
		&player->img.data, &player->img.size_line, &player->img.endian);
	render(player);
	mlx_put_image_to_window(player->mlx_ptr, player->mlx_win, player->img.id,
		0, 0);
	return (1);
}

int			main(int argc, char *argv[])
{
	t_data	*player;
	int		num_sprites;

	if ((argc < 2 || argc > 3) || (!ft_strcmp(argv[1], "--save")))
		ft_exit(3);
	if ((num_sprites = isvalid(argv)) == -1)
		ft_exit(5);
	if (!(player = init_player(argv, argc, num_sprites)))
		ft_exit(5);
	if (!(init_render(player)))
		exit_program(player);
	mlx_hook(player->mlx_win, 17, 0, &exit_program, player);
	mlx_hook(player->mlx_win, 2, 0, &hook_key_press, player);
	mlx_hook(player->mlx_win, 3, 0, &hook_key_release, player);
	mlx_loop_hook(player->mlx_ptr, &hook_key_close, player);
	mlx_loop(player->mlx_ptr);
	return (EXIT_SUCCESS);
}
