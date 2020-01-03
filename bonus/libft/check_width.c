/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 10:58:40 by pcuadrad          #+#    #+#             */
/*   Updated: 2019/12/04 14:38:20 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	check_width(t_printf **bag)
{
	int		i;
	int		cont;

	i = 0;
	cont = 0;
	while ((*bag)->summary[i] && (*bag)->summary[i] != '.')
	{
		if ((*bag)->summary[i] == '*')
		{
			if (((*bag)->width = (int)va_arg((*bag)->argv, int)) < 0)
			{
				(*bag)->minus = 1;
				(*bag)->width *= -1;
			}
			cont++;
		}
		else if (ft_isdigit((*bag)->summary[i]))
		{
			(*bag)->width = ((*bag)->width * 10) + ((*bag)->summary[i] - '0');
			cont++;
		}
		i++;
	}
	if (cont != 0)
		(*bag)->summary = (*bag)->summary + cont;
}
