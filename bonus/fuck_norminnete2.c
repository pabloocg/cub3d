/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fuck_norminnete2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 12:13:44 by pcuadrad          #+#    #+#             */
/*   Updated: 2020/01/10 13:21:24 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int				count_line(char *line)
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
			line[i] == 'E' || line[i] == '3' || line[i] == '4' ||
			line[i] == '5' || line[i] == '6')
			count++;
		i++;
	}
	return (count);
}

int				create_color(int r, int g, int b)
{
	int		color;

	color = r;
	color = (color << 8) | g;
	color = (color << 8) | b;
	return (color);
}

void			delete_sprite(t_data *player, int posx, int posy)
{
	int			i;
	t_sprite	temp;

	i = -1;
	while (++i < player->num_sprites)
	{
		if ((int)player->sprite[i].posx == posx && (int)player->sprite[i].posy
			== posy)
		{
			temp = player->sprite[player->num_sprites - 1];
			player->sprite[player->num_sprites - 1] = player->sprite[i];
			player->sprite[i] = temp;
			break ;
		}
	}
	player->num_sprites -= 1;
}

void			change_sprite(t_data *player, int posx, int posy)
{
	int			i;

	i = -1;
	while (++i < player->num_sprites)
		if ((int)player->sprite[i].posx == posx && (int)player->sprite[i].posy
			== posy)
			player->sprite[i].n_text = 3;
}

int				control_life_enemy(t_data *player, int posx, int posy)
{
	int			i;

	i = -1;
	while (++i < player->num_sprites)
	{
		if ((int)player->sprite[i].posx == posx && (int)player->sprite[i].posy
			== posy)
		{
			player->sprite[i].hp -= (rand() % 3) * 10;
			if (player->sprite[i].hp <= 0)
				return (1);
			break ;
		}
	}
	return (0);
}
