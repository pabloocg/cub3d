/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putchar_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:54:28 by pcuadrad          #+#    #+#             */
/*   Updated: 2019/12/04 14:36:26 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	putchar_printf_1minus(int c, t_printf **bag)
{
	int		diff;

	diff = 0;
	ft_putchar(c);
	(*bag)->size += 1;
	if ((*bag)->width > 0)
		diff = (*bag)->width - 1;
	if (diff >= 0 && (*bag)->width > 0)
	{
		putspaces(diff);
		(*bag)->size += diff;
	}
}

static void	putchar_printf_0minus(int c, t_printf **bag)
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
	ft_putchar(c);
	(*bag)->size += 1;
}

void		putchar_printf(t_printf **bag)
{
	char	c;

	c = va_arg((*bag)->argv, int);
	if ((*bag)->minus == 1)
		putchar_printf_1minus(c, bag);
	else if ((*bag)->minus == 0)
		putchar_printf_0minus(c, bag);
}
