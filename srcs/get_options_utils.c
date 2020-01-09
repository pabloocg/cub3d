/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 12:46:19 by pcuadrad          #+#    #+#             */
/*   Updated: 2020/01/09 13:51:56 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	create_map(char *line, int x, t_data *player, int *sp_x)
{
	int	i;
	int	y;

	i = -1;
	y = 0;
	while (line[++i])
	{
		if (line[i] == '1' || line[i] == '0')
			player->map.tab_map[x][y++] = line[i] - '0';
		else if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W' ||
			line[i] == 'E')
		{
			player->posx = (double)x + 0.5;
			player->posy = (double)y + 0.5;
			get_coordenate(player, line[i]);
			player->map.tab_map[x][y++] = 0;
		}
		else if (line[i] == '2')
		{
			player->sprite[*sp_x].posx = (double)x + 0.5;
			player->sprite[*sp_x].posy = (double)y + 0.5;
			player->map.tab_map[x][y++] = 2;
			*sp_x += 1;
		}
	}
}

int		check_map_bg(char *line)
{
	int		i;
	int		ok;
	int		len;

	i = 0;
	ok = 0;
	len = ft_strlen(line) - 1;
	while (line[i] == ' ' && line[i])
		i++;
	if (line[i] == '1' && line[i])
		ok = 1;
	if (ok == 0)
		return (0);
	ok = 0;
	while (line[len] == ' ' && line[len])
		len--;
	if (line[len] == '1' && line[len])
		ok = 1;
	return ((ok == 1) ? 1 : 0);
}

int		count_line(char *line)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (line[i])
	{
		while (line[i] && line[i] == ' ')
			i++;
		if (line[i] == '2' || line[i] == '1' || line[i] == '0' ||
			line[i] == 'N' || line[i] == 'S' || line[i] == 'W' ||
			line[i] == 'E')
			count++;
		i++;
	}
	return (count);
}

void	isfirst_or_last_line(char *line, t_data *player)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != ' ')
		{
			free(line);
			free(player->map.tab_map);
			free_path_textures(player, 1);
			free(player->sprite);
			free(player);
			ft_exit(2);
		}
		i++;
	}
}
