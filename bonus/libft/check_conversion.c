/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_conversion_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 11:59:49 by pcuadrad          #+#    #+#             */
/*   Updated: 2019/12/04 14:38:11 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	check_conversion(t_printf **bag)
{
	int		i;

	i = 0;
	if ((*bag)->summary[i] == 'l' && (*bag)->summary[i + 1] != 'l')
	{
		(*bag)->mask = 'l';
		i++;
	}
	else if ((*bag)->summary[i] == 'l' && (*bag)->summary[i + 1] == 'l')
	{
		(*bag)->mask = 'd';
		i++;
	}
	else if ((*bag)->summary[i] == 'h' && (*bag)->summary[i + 1] != 'h')
	{
		(*bag)->mask = 'h';
		i++;
	}
	else if ((*bag)->summary[i] == 'h' && (*bag)->summary[i + 1] == 'h')
	{
		(*bag)->mask = 'D';
		i++;
	}
	(*bag)->conversion = (*bag)->summary[i];
}
