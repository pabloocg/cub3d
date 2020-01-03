/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_precisition.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 11:16:07 by pcuadrad          #+#    #+#             */
/*   Updated: 2019/12/04 14:38:17 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	check_precision_aux1(int *cont, t_printf **bag, int *i)
{
	while (ft_isdigit((*bag)->summary[*i]))
	{
		(*bag)->precision = ((*bag)->precision * 10)
			+ ((*bag)->summary[*i] - '0');
		*cont += 1;
		*i += 1;
	}
}

static void	check_precision_aux2(int *cont, t_printf **bag, int *i)
{
	(*bag)->precision = -1;
	*cont += 1;
	*i += 1;
}

void		check_precision(t_printf **bag)
{
	int		i;
	int		cont;

	i = -1;
	cont = 0;
	while ((*bag)->summary[++i])
		if ((*bag)->summary[i] == '.')
		{
			i++;
			cont++;
			(*bag)->precision = 0;
			if ((*bag)->summary[i] == '*')
			{
				if (((*bag)->precision = (int)va_arg((*bag)->argv, int)) < 0)
					(*bag)->precision = -1;
				cont++;
			}
			else if ((*bag)->summary[i] == '-')
				check_precision_aux2(&cont, bag, &i);
			if (ft_isdigit((*bag)->summary[i]))
				check_precision_aux1(&cont, bag, &i);
		}
	(*bag)->summary = (*bag)->summary + cont;
}
