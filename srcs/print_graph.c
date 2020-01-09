/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_graph.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 20:15:21 by pablo             #+#    #+#             */
/*   Updated: 2020/01/09 18:25:59 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	get_color(t_color pixel)
{
	int		color;

	color = pixel.r;
	color = (color << 8) | pixel.g;
	color = (color << 8) | pixel.b;
	return (color);
}

void		print_column(t_data *player, int end, int coord,
	t_text texture)
{
	int		y;
	int		row;
	double	how_x;
	double	how_y;

	how_x = (int)(player->ray.wallhit_x * (double)(texture.w));
	if (player->ray.side == 0 && player->ray.raydirx > 0)
		how_x = texture.w - how_x - 1;
	if (player->ray.side == 1 && player->ray.raydiry < 0)
		how_x = texture.w - how_x - 1;
	y = 0;
	while (y < player->ray.drawstart)
		player->img.image[(y++ * player->map.width) + coord] =
			get_color(player->textur.ceilling_color);
	while (y < end)
	{
		row = y * 256 - player->map.height * 128 + player->ray.lineheight * 128;
		how_y = ((row * texture.h) / player->ray.lineheight) / 256;
		player->img.image[(y++ * player->map.width) + coord] =
			get_pixel(&texture, how_y, how_x);
	}
	while (y < player->map.height)
		player->img.image[(y++ * player->map.width) + coord] =
			get_color(player->textur.floor_color);
}

static void	print_sprite__aux(t_data *player, int texx, int stripe)
{
	int				texy;
	int				y;
	unsigned int	color;

	y = player->ray_sprite.drawstarty;
	while (++y < player->ray_sprite.drawendy && y < player->map.height)
	{
		player->ray_sprite.print_y = ((int)(y - player->ray_sprite.
		vmovescreen) * 256.) - (player->map.height * 128.) + (player->
		ray_sprite.spriteheight * 128.);
		texy = ((player->ray_sprite.print_y * player->textur.sprite.h)
			/ player->ray_sprite.spriteheight) / 256.;
		color = player->textur.sprite.image[(player->textur.sprite.w *
			texy) + texx];
		if (color != 0)
			player->img.image[(y * player->map.width) + stripe] = color;
	}
}

void		print_sprite(t_data *player)
{
	int				stripe;
	int				texx;

	stripe = player->ray_sprite.drawstartx - 1;
	while (++stripe < player->ray_sprite.drawendx && stripe < player->map.width)
	{
		texx = (int)(256 * (((int)(stripe) - (-player->ray_sprite.spritewidth
		/ 2 + player->ray_sprite.spritescreenx))) * player->textur.sprite.w /
		player->ray_sprite.spritewidth) / 256;
		if (player->ray_sprite.transformy > 0 && player->ray_sprite.transformy
		< player->depth[(int)stripe])
			print_sprite__aux(player, texx, stripe);
	}
}

int		get_color_bmp(unsigned char *image, int x, int y, t_data *player)
{
	int	rgb;
	int	color;

	color = *(int*)(image + (4 * player->map.width * (player->map.height - 1 - y)) + (4 * x));
	rgb = (color & 0xFF0000) | (color & 0x00FF00) | (color & 0x0000FF);
	return (rgb);
}
