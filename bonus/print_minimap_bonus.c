/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_minimap_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 18:24:37 by pcuadrad          #+#    #+#             */
/*   Updated: 2020/01/09 18:51:20 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void		print_cub_mini(t_data *player, int x, int y , int size, int color)
{
	int		w;
	int		h;

	w = -1;
	while (++w < size && (h = -1))
		while (++h < size)
		{
			if (((y + h) < player->map.height) && ((w + x) < player->map.width))
				player->img.image[((y + h) * player->map.width) + (w + x)] = color;
		}
}

void			print_map(t_data *player)
{
	int		x;
	int		y;
	int		x_p;
	int		y_p;
	int		size;

	x = -1;
	y_p = 0;
	size = (((player->map.width / 2) + (player->map.height / 2)) / ((24 / 2) * (24 / 2)));
	while (++x < player->map.x_max)
	{
		y = -1;
		x_p = 0;
		while (++y < player->map.y_max)
		{
			x_p += size;
			if (player->map.tab_map[x][y] == 1)
				print_cub_mini(player, x_p, y_p, size, create_color(0, 0, 0));
			else if (x == (int)player->posX && y == (int)player->posY)
				print_cub_mini(player, x_p, y_p, size, create_color(200, 0, 0));
			else
				print_cub_mini(player, x_p, y_p, size, create_color(255, 255, 255));
		}
		y_p += size;
	}
}
