/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_param2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 18:47:24 by pcuadrad          #+#    #+#             */
/*   Updated: 2020/01/09 13:48:57 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		check_color_aux2(char *cpyline, int i)
{
	int		control;

	control = 0;
	while (cpyline[i] == ',' || cpyline[i] == ' ')
	{
		if (cpyline[i] == ',')
			control = 1;
		i++;
	}
	if (control == 0)
		return (0);
	while (ft_isdigit(cpyline[i]))
		i++;
	control = 0;
	while (cpyline[i] == ',' || cpyline[i] == ' ')
	{
		if (cpyline[i] == ',')
			control = 1;
		i++;
	}
	if (control == 0)
		return (0);
	return (1);
}

int		check_color_aux1(char *cpyline, char coord)
{
	int		i;
	int		control;

	i = 0;
	control = 0;
	while (cpyline[i] == coord || cpyline[i] == ' ')
	{
		i++;
		if (cpyline[i] == ' ')
			control = 1;
	}
	if (control == 0)
		return (0);
	control = 0;
	while (ft_isdigit(cpyline[i]))
	{
		i++;
		control = 1;
	}
	if (control == 0)
		return (0);
	if (!(check_color_aux2(cpyline, i)))
		return (0);
	return (1);
}

int		check_color(char *line, t_valid *check)
{
	char	*cpyline;
	int		i;

	cpyline = line;
	i = 0;
	if (ft_strchr(cpyline, 'F'))
	{
		if (!(check_color_aux1(cpyline, 'F')))
			return (0);
		check->floor = 1;
		return (1);
	}
	else if (ft_strchr(cpyline, 'C'))
	{
		if (!(check_color_aux1(cpyline, 'C')))
			return (0);
		check->ceilling = 1;
		return (1);
	}
	return (0);
}

int		check_sprite(char *line, t_valid *check)
{
	char *cpyline;

	cpyline = line;
	check->sp_text = 0;
	while (*cpyline == 'S')
	{
		cpyline++;
		check->sp_text = 1;
	}
	if (check->sp_text == 0)
		return (0);
	check->sp_text = 0;
	while (*cpyline == ' ')
	{
		cpyline++;
		check->sp_text = 1;
	}
	if (check->sp_text == 0)
		return (0);
	check->sp_text = 0;
	if (*cpyline != '\0')
		check->sp_text = 1;
	else
		return (0);
	return (1);
}
