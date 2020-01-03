/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 11:58:52 by pcuadrad          #+#    #+#             */
/*   Updated: 2019/12/26 15:32:29 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
		get_sprite(player, (char*)cpyline);
	else if (ft_strstr(cpyline, "F"))
		get_colors((char*)cpyline, &player->textur.floor_color, 'F');
	else if (ft_strstr(cpyline, "C"))
		get_colors((char*)cpyline, &player->textur.ceilling_color, 'C');
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

data_t		*init_player(char *argv[], int argc, int num_sprites)
{
	data_t  *player;

	if (!(player = (data_t*)malloc(sizeof(data_t))))
		return (NULL);
	player->num_sprites = num_sprites;
	if (!(player->sprite = malloc(sizeof(sprite_t) * player->num_sprites)))
		return (NULL);
	if (!(read_param(player, argv[1])))
		return (NULL);
	if (!(player->mlx_ptr = mlx_init()))
		return (NULL);
	charge_textures_main(player);
	if (argc == 3)
		bmp_check(player, argv);
	return (player);
}