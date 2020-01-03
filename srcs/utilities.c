/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 19:28:28 by pcuadrad          #+#    #+#             */
/*   Updated: 2019/12/21 19:28:28 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

double		ft_pow(double num)
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

int		exit_program(data_t *player)
{
	free_all(player);
	ft_printf("Saliendo del programa..\n");
	exit(EXIT_SUCCESS);
}