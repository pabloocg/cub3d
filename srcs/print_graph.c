/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_graph_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 20:15:21 by pablo             #+#    #+#             */
/*   Updated: 2020/01/10 14:11:32 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void		print_column(t_data *player, int end, int coord,
	t_text texture)
{
	int		y;
	int		row;
	int		how_x;
	int		how_y;

	how_x = (int)(player->ray.wallhit_x * (double)(texture.w));
	if (player->ray.side == 0 && player->ray.raydirx > 0)
		how_x = texture.w - how_x - 1;
	if (player->ray.side == 1 && player->ray.raydiry < 0)
		how_x = texture.w - how_x - 1;
	y = player->ray.drawstart;
	while (y < end)
	{
		row = y * 256 - player->map.height * 128 + player->ray.lineheight * 128;
		how_y = ((row * texture.h) / player->ray.lineheight) / 256;
		player->img.image[(y++ * player->map.width) + coord] =
			get_pixel(&texture, how_y, how_x);
	}
}

static void	print_sprite__aux(t_data *player, int texx, int stripe, int i)
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
		texy = ((player->ray_sprite.print_y * player->textur.sprite[
		player->sprite[player->ray_sprite.spriteorder[i]].n_text].h)
		/ player->ray_sprite.spriteheight) / 256.;
		color = player->textur.sprite[player->sprite[player->
		ray_sprite.spriteorder[i]].n_text].image[(player->textur.sprite[
		player->sprite[player->ray_sprite.spriteorder[i]].n_text].w *
		texy) + texx];
		if (((player->sprite[player->ray_sprite.spriteorder[i]].n_text != 1 &&
		color != 0) && (player->sprite[player->ray_sprite.spriteorder[i]].n_text
		!= 3 && color != 0)) || (player->sprite[player->ray_sprite.spriteorder
		[i]].n_text == 1 && color != 9961608) || (player->sprite[player->
		ray_sprite.spriteorder[i]].n_text == 3 && color != 9961608))
			player->img.image[(y * player->map.width) + stripe] = color;
	}
}

void		print_sprite(t_data *player, int i)
{
	int				stripe;
	int				texx;

	stripe = player->ray_sprite.drawstartx - 1;
	while (++stripe < player->ray_sprite.drawendx && stripe < player->map.width)
	{
		texx = (int)(256 * (((int)(stripe) - (-player->ray_sprite.spritewidth
		/ 2 + player->ray_sprite.spritescreenx))) * player->textur.sprite[
		player->sprite[player->ray_sprite.spriteorder[i]].n_text].w /
		player->ray_sprite.spritewidth) / 256;
		if (player->ray_sprite.transformy > 0 && player->ray_sprite.transformy
			< player->depth[(int)stripe])
			print_sprite__aux(player, texx, stripe, i);
	}
}
