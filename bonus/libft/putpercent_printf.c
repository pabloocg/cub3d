/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putpercent_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 14:09:01 by pcuadrad          #+#    #+#             */
/*   Updated: 2019/12/04 14:37:00 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	putpercent_printf_1minus(t_printf **bag)
{
	int		diff;

	diff = 0;
	ft_putchar('%');
	(*bag)->size += 1;
	if ((*bag)->width > 0)
		diff = (*bag)->width - 1;
	if (diff >= 0 && (*bag)->width > 0)
	{
		putspaces(diff);
		(*bag)->size += diff;
	}
}

static void	putpercent_printf_0minus(t_printf **bag)
{
	int		diff;

	diff = 0;
	if ((*bag)->width > 0)
		diff = (*bag)->width - 1;
	if (diff >= 0 && (*bag)->width > 0)
	{
		putspaces(diff);
		(*bag)->size += diff;
	}
	ft_putchar('%');
	(*bag)->size += 1;
}

static void	putpercent_printf_zeros(t_printf **bag)
{
	int		diff;

	diff = 0;
	if ((*bag)->width > 0)
		diff = (*bag)->width - 1;
	if (diff >= 0 && (*bag)->width > 0)
	{
		putzeros(diff);
		(*bag)->size += diff;
	}
	ft_putchar('%');
	(*bag)->size += 1;
}

void		putpercent_printf(t_printf **bag)
{
	if ((*bag)->minus == 1)
		putpercent_printf_1minus(bag);
	else if ((*bag)->minus == 0)
	{
		if ((*bag)->zero == 1)
			putpercent_printf_zeros(bag);
		else
			putpercent_printf_0minus(bag);
	}
}
