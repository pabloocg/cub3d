/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 19:28:28 by pcuadrad          #+#    #+#             */
/*   Updated: 2020/01/10 11:40:57 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int			get_pixel(t_text *image, double y, double x)
{
	int		pos;

	if (x < 0 || y < 0 || x > image->w || y > image->h)
		return (0);
	pos = ((int)(double)((y * image->w) + x));
	return ((int)image->image[(int)pos]);
}

double		ft_pow(double num)
{
	return (num * num);
}

void		ft_exit(int control)
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

int			exit_program(t_data *player)
{
	free_all(player);
	ft_printf("Exiting the program...\n");
	exit(EXIT_SUCCESS);
}

int			exit_program_bmp(t_data *player)
{
	free_all_bmp(player);
	ft_printf("Exiting the program...\n");
	exit(EXIT_SUCCESS);
}
