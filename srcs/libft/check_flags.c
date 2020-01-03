/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:01:55 by pcuadrad          #+#    #+#             */
/*   Updated: 2019/12/04 14:38:14 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_minus(t_printf **bag, char c)
{
	if (c == '-')
	{
		(*bag)->minus = 1;
		return (1);
	}
	return (0);
}

static int	check_plus(t_printf **bag, char c)
{
	if (c == '+')
	{
		(*bag)->minus = 1;
		return (1);
	}
	return (0);
}

static int	check_zero(t_printf **bag, char c, char c1)
{
	if (c == '0' && ((!ft_isdigit(c1) && c1 != '.') || c1 == '0'))
	{
		(*bag)->zero = 1;
		return (1);
	}
	return (0);
}

void		check_flags(t_printf **bag)
{
	int		i;
	int		cont;

	i = -1;
	cont = 0;
	while ((*bag)->summary[++i])
	{
		if (check_minus(bag, (*bag)->summary[i]))
			cont++;
		if (check_zero(bag, (*bag)->summary[i], (*bag)->summary[i - 1]))
			cont++;
		if ((*bag)->summary[i] == ' ')
		{
			(*bag)->space = 1;
			cont++;
		}
		if (check_plus(bag, (*bag)->summary[i]))
			cont++;
		if ((*bag)->summary[i] == '#')
		{
			(*bag)->hash = 1;
			cont++;
		}
	}
	(*bag)->summary = (*bag)->summary + cont;
}
