/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_graph.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 20:15:21 by pablo             #+#    #+#             */
/*   Updated: 2020/01/02 14:21:45 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	get_pixel(text_t *image, double y, double x)
{
	int		pos;

	if (x < 0 || y < 0 || x > image->w || y > image->h)
		return (0);
	pos = ((int)(double)((y * image->w) + x));
	return ((int)image->image[(int)pos]);
}

static int	get_color(color_t pixel)
{
	int		color;

	color = pixel.r;
	color = (color << 8) | pixel.g;
	color = (color << 8) | pixel.b;
	return (color);
}

void		print_column(data_t *player, int start, int end, int coord,
	text_t texture)
{
	int		y;
	int		row;
	double	how_x;
	double	how_y;

	how_x = (int)(player->ray.wallhit_x * (double)(texture.w));
    if(player->ray.side == 0 && player->ray.rayDirX > 0)
		how_x = texture.w - how_x - 1;
    if(player->ray.side == 1 && player->ray.rayDirY < 0)
		how_x = texture.w - how_x - 1;
	y = 0;
	while (y < start)
		player->img.image[(y++ * player->map.width) + coord] =
			get_color(player->textur.ceilling_color);
	while (y < end)
	{
		row = y * 256 - player->map.height * 128 + player->ray.lineHeight * 128;
        how_y = ((row * texture.h) / player->ray.lineHeight) / 256;
		player->img.image[(y++ * player->map.width) + coord] =
			get_pixel(&texture, how_y, how_x);
	}
	while (y < player->map.height)
		player->img.image[(y++ * player->map.width) + coord] =
			get_color(player->textur.floor_color);
}
