/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 12:44:05 by pcuadrad          #+#    #+#             */
/*   Updated: 2019/12/26 14:13:11 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_textures(data_t *player, char *line)
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

void	get_colors(char *line, color_t *color, char param)
{
	color->empty = 0;
	while (*line == ' ' || *line == param)
		line++;
	color->r = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	while (*line == ' ' || *line == ',')
		line++;
	color->g = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	while (*line == ' ' || *line == ',')
		line++;
	color->b = ft_atoi(line);
}

void	get_sprite(data_t *player, char *line)
{
	while (*line == ' ' || *line == 'S')
			line++;
	player->textur.sprite.path = ft_strdup(line);
}

void	get_resolution(data_t *player, char *line)
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
	player->map.height = ft_atoi(line);
	if (player->map.height > 1395)
		player->map.height = 1395;
}

int		get_map_numbers(int fd_open, data_t *player)
{
	char	*line;
	int		x;
	int		count;
	int		sp_x;

	x = 0;
	count = 0;
	sp_x = 0;
	while (get_next_line(fd_open, &line) > 0)
	{
		if (check_map_bg(line))
		{
			if (count == 0 || count == player->map.x_max)
				isfirst_or_last_line(line, player);
			player->map.y_max = count_line(line);
			if (!(player->map.tab_map[x] = (int*)malloc(sizeof(int) * player->map.y_max)))
				return (0);
			create_map(line, x, player, &sp_x);
			x++;
			count++;
		}
		free(line);
	}
	free(line);
	return (1);
}