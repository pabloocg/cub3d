/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_param.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 18:12:15 by pcuadrad          #+#    #+#             */
/*   Updated: 2020/01/09 13:50:10 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		check_map(t_valid *check)
{
	if (check->resolution == 0 || check->n_text == 0 || check->s_text == 0 ||
		check->w_text == 0 || check->e_text == 0 || check->ceilling == 0 ||
		check->floor == 0 || check->sp_text == 0)
		return (0);
	return (1);
}

int		check_texture_c(char *cpyline, char coord1, char coord2)
{
	int		i;
	int		control;

	i = 0;
	if (ft_strchr(cpyline, coord1))
	{
		control = 0;
		while (cpyline[i] == coord1 || cpyline[i] == coord2)
			i++;
		while (cpyline[i] == ' ')
		{
			control = 1;
			i++;
		}
		if (control != 1)
			return (0);
		if (cpyline[i] == '\0')
			return (0);
	}
	return (1);
}

int		check_textures(char *line, t_valid *check)
{
	if (ft_strchr(line, 'N'))
	{
		if (!(check_texture_c(line, 'N', 'O')))
			return (0);
		check->n_text = 1;
	}
	else if (ft_strchr(line, 'S'))
	{
		if (!(check_texture_c(line, 'S', 'O')))
			return (0);
		check->s_text = 1;
	}
	else if (ft_strchr(line, 'W'))
	{
		if (!(check_texture_c(line, 'W', 'E')))
			return (0);
		check->w_text = 1;
	}
	else if (ft_strchr(line, 'E'))
	{
		if (!(check_texture_c(line, 'E', 'A')))
			return (0);
		check->e_text = 1;
	}
	return (1);
}

int		check_width_heigth(char *cpyline, int i, t_valid *check)
{
	check->resolution = 0;
	while (ft_isdigit(cpyline[++i]))
		check->resolution = 1;
	if (check->resolution == 0)
		return (0);
	check->resolution = 0;
	while (cpyline[i] == ' ')
	{
		i++;
		check->resolution = 1;
	}
	if (check->resolution == 0)
		return (0);
	if (cpyline[i] == '-')
		return (0);
	check->resolution = 0;
	while (ft_isdigit(cpyline[i]))
	{
		i++;
		check->resolution = 1;
	}
	if (check->resolution == 0)
		return (0);
	return ((cpyline[i] == '\0') ? 1 : 0);
}

int		check_resolution(char *line, t_valid *check)
{
	char	*cpyline;
	int		i;

	i = 0;
	check->resolution = 0;
	cpyline = line;
	while (cpyline[i] == ' ')
		i++;
	if (cpyline[i] == 'R' && cpyline[i + 1] == ' ')
		check->resolution = 1;
	if (check->resolution == 0)
		return (0);
	while (cpyline[i] == 'R' || cpyline[i] == ' ')
		i++;
	if (cpyline[i] == '-')
		return (0);
	if (!(check_width_heigth(cpyline, i - 1, check)))
		return (0);
	return (1);
}
