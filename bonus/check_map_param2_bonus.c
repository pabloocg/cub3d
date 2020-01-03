/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_param2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 18:47:24 by pcuadrad          #+#    #+#             */
/*   Updated: 2019/12/28 18:23:51 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int     check_sprite(char *line, valid_t *check, char letter)
{
	char *cpyline;

	cpyline = line;
	check->sp_text = 0;
	while (*cpyline == letter)
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