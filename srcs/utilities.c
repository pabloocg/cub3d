/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:52:27 by pcuadrad          #+#    #+#             */
/*   Updated: 2020/01/09 14:13:48 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

double	ft_pow(double num)
{
	return (num * num);
}

void	ft_exit(int control)
{
	if (control == 1)
		ft_printf("The file is not valid!\n");
	else if (control == 2)
		ft_printf("Wrong parameters.\nPlease fixed!!\n");
	else if (control == 3)
		ft_printf("Error\nThe syntax is ./cub3D < file.cub > < --save >\n");
	else if (control == 4)
		ft_printf("Fail charging textures.\n");
	else if (control == 5)
		ft_printf("Error malloc allocate memory.\n");
	exit(EXIT_FAILURE);
}

int		exit_program(t_data *player)
{
	free_all(player);
	ft_printf("Exiting the program...\n");
	exit(EXIT_SUCCESS);
}

int		get_distance_sprites(t_data *player)
{
	int	i;

	if (!(player->ray_sprite.spriteorder = (int*)malloc(sizeof(int) *
		player->num_sprites)))
		return (0);
	if (!(player->ray_sprite.spritedistance = (double*)malloc(sizeof(double) *
		player->num_sprites)))
		return (0);
	i = -1;
	while (++i < player->num_sprites)
	{
		player->ray_sprite.spriteorder[i] = i;
		player->ray_sprite.spritedistance[i] = (ft_pow((player->posx -
			player->sprite[i].posx)) + ft_pow((player->posy -
			player->sprite[i].posy)));
	}
	return (1);
}

int		get_pixel(t_text *image, double y, double x)
{
	int		pos;

	if (x < 0 || y < 0 || x > image->w || y > image->h)
		return (0);
	pos = ((int)(double)((y * image->w) + x));
	return ((int)image->image[(int)pos]);
}
