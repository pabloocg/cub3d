/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 12:46:19 by pcuadrad          #+#    #+#             */
/*   Updated: 2020/01/10 12:42:35 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	get_sprites_coordenates_aux(t_data *player, int x, int *y, int texture)
{
	player->sprite[player->map.sp_x].posx = (double)x + 0.5;
	player->sprite[player->map.sp_x].posy = (double)*y + 0.5;
	player->sprite[player->map.sp_x].n_text = texture;
}

void	get_sprites_coordenates_2(t_data *player, char number, int x, int *y)
{
	if (number == '4')
	{
		get_sprites_coordenates_aux(player, x, y, 2);
		player->map.tab_map[x][*y] = 4;
	}
	else if (number == '5')
	{
		get_sprites_coordenates_aux(player, x, y, 4);
		player->map.tab_map[x][*y] = 5;
	}
	else if (number == '6')
	{
		get_sprites_coordenates_aux(player, x, y, 5);
		player->map.tab_map[x][*y] = 6;
	}
}

void	get_sprites_coordenates(t_data *player, char number, int x, int *y)
{
	if (number == '2')
	{
		get_sprites_coordenates_aux(player, x, y, 0);
		player->map.tab_map[x][*y] = 2;
	}
	else if (number == '3')
	{
		get_sprites_coordenates_aux(player, x, y, 1);
		player->sprite[player->map.sp_x].hp = 100;
		player->map.tab_map[x][*y] = 3;
	}
	else
		get_sprites_coordenates_2(player, number, x, y);
	*y += 1;
	player->map.sp_x += 1;
}

void	create_map(char *line, int x, t_data *player)
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
		else if (line[i] == '2' || line[i] == '3' || line[i] == '4' ||
			line[i] == '5' || line[i] == '6')
			get_sprites_coordenates(player, line[i], x, &y);
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
