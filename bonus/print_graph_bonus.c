/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_graph_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 20:15:21 by pablo             #+#    #+#             */
/*   Updated: 2020/01/09 18:51:07 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static int	get_pixel(text_t *image, int y, int x)
{
	int		pos;

	if (x < 0 || y < 0 || x > image->w || y > image->h)
		return (0);
	pos = ((int)(double)((y * image->w) + x));
	return ((int)image->image[(int)pos]);
}

void		print_column(t_data *player, int start, int end, int coord,
	text_t texture)
{
	int		y;
	int		row;
	int		how_x;
	int		how_y;

	how_x = (int)(player->ray.wallhit_x * (double)(texture.w));
    if(player->ray.side == 0 && player->ray.rayDirX > 0)
		how_x = texture.w - how_x - 1;
    if(player->ray.side == 1 && player->ray.rayDirY < 0)
		how_x = texture.w - how_x - 1;
	y = start;
	while (y < end)
	{
		row = y * 256 - player->map.height * 128 + player->ray.lineHeight * 128;
        how_y = ((row * texture.h) / player->ray.lineHeight) / 256;
		player->img.image[(y++ * player->map.width) + coord] =
			get_pixel(&texture, how_y, how_x);
	}
}
