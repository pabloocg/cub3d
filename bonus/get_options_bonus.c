/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 12:44:05 by pcuadrad          #+#    #+#             */
/*   Updated: 2020/01/10 12:56:45 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	get_textures(t_data *player, char *line)
{
	if (ft_strstr((const char*)line, "NO"))
	{
		while (*line == ' ' || *line == 'N' || *line == 'O')
			line++;
		player->textur.north_text.path = ft_strdup(line);
	}
	else if (ft_strstr((const char*)line, "SO"))
	{
		while (*line == ' ' || *line == 'S' || *line == 'O')
			line++;
		player->textur.south_text.path = ft_strdup(line);
	}
	else if (ft_strstr((const char*)line, "WE"))
	{
		while (*line == ' ' || *line == 'W' || *line == 'E')
			line++;
		player->textur.weast_text.path = ft_strdup(line);
	}
	else if (ft_strstr((const char*)line, "EA"))
	{
		while (*line == ' ' || *line == 'E' || *line == 'A')
			line++;
		player->textur.east_text.path = ft_strdup(line);
	}
}

void	get_colors(char *line, t_data *player, char param)
{
	if (param == 'F')
	{
		while (*line == ' ' || *line == param)
			line++;
		player->textur.floor.path = ft_strdup(line);
	}
	else if (param == 'C')
	{
		while (*line == ' ' || *line == param)
			line++;
		player->textur.ceilling.path = ft_strdup(line);
	}
}

void	get_sprite(t_data *player, char *line, char letter)
{
	if (letter == 'S')
	{
		while (*line == ' ' || *line == letter)
			line++;
		player->textur.sprite[0].path = ft_strdup(line);
		player->textur.sprite[1].path = ft_strdup("textures/enemy2.xpm");
		player->textur.sprite[2].path = ft_strdup("textures/life.xpm");
		player->textur.sprite[3].path = ft_strdup("textures/enemy_died.xpm");
		player->textur.sprite[4].path = ft_strdup("textures/sprite3.xpm");
		player->textur.sprite[5].path = ft_strdup("textures/bullets.xpm");
	}
	else if (letter == 'L')
	{
		while (*line == ' ' || *line == letter)
			line++;
		player->textur.layaout.path = ft_strdup(line);
	}
	else if (letter == 'G')
	{
		while (*line == ' ' || *line == letter)
			line++;
		player->textur.gun.path = ft_strdup(line);
		player->textur.gunshot.path = ft_strdup("textures/shot.xpm");
	}
}

void	get_resolution(t_data *player, char *line)
{
	while (*line == ' ' || *line == 'R')
		line++;
	player->map.width = ft_atoi(line);
	if (player->map.width > 2560)
		player->map.width = 2560;
	while (ft_isdigit(*line))
		line++;
	while (*line == ' ')
		line++;
	player->map.screen_height = ft_atoi(line);
	if (player->map.screen_height > 1395)
		player->map.screen_height = 1395;
	player->map.height = player->map.screen_height -
		(player->map.screen_height / 4);
}

int		get_map_numbers(int fd_open, t_data *player)
{
	char	*line;
	int		x;
	int		count;

	x = 0;
	count = 0;
	player->map.sp_x = 0;
	while (get_next_line(fd_open, &line) > 0)
	{
		if (check_map_bg(line))
		{
			if (count == 0 || count == player->map.x_max)
				isfirst_or_last_line(line, player);
			player->map.y_max = count_line(line);
			if (!(player->map.tab_map[x] = (int*)malloc(sizeof(int) *
				player->map.y_max)))
				return (0);
			create_map(line, x, player);
			x++;
			count++;
		}
		free(line);
	}
	free(line);
	return (1);
}
