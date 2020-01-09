/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 11:58:52 by pcuadrad          #+#    #+#             */
/*   Updated: 2020/01/09 11:03:17 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	parse_map(data_t *player, char *line)
{
	const char	*cpyline;

	cpyline = line;
	if (check_map_bg((char*)cpyline))
		player->map.x_max += 1;
	else if (ft_strstr(cpyline, "R"))
		get_resolution(player, (char*)cpyline);
	else if (ft_strstr(cpyline, "NO") || ft_strstr(cpyline, "EA") ||
			ft_strstr(cpyline, "WE") || ft_strstr(cpyline, "SO"))
		get_textures(player, (char*)cpyline);
	else if (ft_strstr(cpyline, "S"))
		get_sprite(player, (char*)cpyline, 'S');
	else if (ft_strstr(cpyline, "L"))
		get_sprite(player, (char*)cpyline, 'L');
	else if (ft_strstr(cpyline, "G"))
		get_sprite(player, (char*)cpyline, 'G');
	else if (ft_strstr(cpyline, "F"))
		get_colors((char*)cpyline, player, 'F');
	else if (ft_strstr(cpyline, "C"))
		get_colors((char*)cpyline, player, 'C');
}

int			read_map(data_t *player, char *file)
{
	int		fd_open;

	if (player->map.x_max > 0)
	{
		if (!(player->map.tab_map = (int**)malloc(sizeof(int*) * player->map.x_max)))
			return (0);
	}
	else
		return (0);
	fd_open = open(file, O_RDONLY);
	if (!(get_map_numbers(fd_open, player)))
		return (0);
	close(fd_open);
	return (1);
}

int			read_param(data_t *player, char *file)
{
	int		fd_open;
	char	*line;

	if ((fd_open = open(file, O_RDONLY)) < 0)
	{
		free(player->sprite);
		free(player);
		ft_exit(1);
	}
	player->map.x_max = 0;
	player->map.y_max = 0;
	while ((get_next_line(fd_open, &line)) > 0)
	{
		parse_map(player, line);
		free(line);
	}
	free(line);
	close(fd_open);
	if (!(read_map(player, file)))
		return (0);
	return (1);
}

data_t		*init_player(char *argv[], int argc, int num_sprites, int lifes)
{
	data_t  *player;

	if (!(player = (data_t*)malloc(sizeof(data_t))))
		return (NULL);
	player->init_game = 0;
	player->argc = argc;
	player->argv[0] = argv[0];
	player->argv[1] = argv[1];
	player->num_sprites = num_sprites;
	player->hp_max = 100.;
	player->hp_current = player->hp_max;
	player->bullet_max = 20;
	player->bullet_current = player->bullet_max;
	player->items_current = 0;
	player->lifes = lifes;
	if (!(player->sprite = (sprite_t*)malloc(sizeof(sprite_t) * player->num_sprites)))
		return (NULL);
	if (!(player->textur.sprite = (text_t*)malloc(sizeof(text_t) * 6)))
		return (NULL);
	if (!(read_param(player, argv[1])))
		return (NULL);
	if (!(player->mlx_ptr = mlx_init()))
		return (NULL);
	charge_textures_main(player);
	get_crosshair(player);
	if (argc == 3)
		bmp_check(player, argv);
	return (player);
}
