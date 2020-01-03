/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_printf_aux.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 14:43:22 by pcuadrad          #+#    #+#             */
/*   Updated: 2019/12/04 14:36:49 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_intmax	putnbr_check_zero(t_printf **bag)
{
	t_intmax		number;

	if ((*bag)->mask == 'l')
		number = (long int)va_arg((*bag)->argv, long int);
	else if ((*bag)->mask == 'd')
		number = (long long int)va_arg((*bag)->argv, long long int);
	else if ((*bag)->mask == 'h')
		number = (short int)va_arg((*bag)->argv, int);
	else if ((*bag)->mask == 'D')
		number = (signed char)va_arg((*bag)->argv, int);
	else
		number = (int)va_arg((*bag)->argv, int);
	if (number == 0 && (*bag)->precision != -1)
	{
		putnbr_print_0(bag);
		return (0);
	}
	number = (t_intmax)number;
	return (number);
}

void		putnbr_width_prec(t_printf **bag, int len, int neg)
{
	int		diff;

	diff = 0;
	if ((*bag)->width > len)
	{
		if ((*bag)->precision > len)
			diff = (*bag)->width - (*bag)->precision - neg;
		else
			diff = (*bag)->width - len - neg;
		if (diff >= 0)
		{
			putspaces(diff);
			(*bag)->size += diff;
		}
	}
}

void		putnbr_prec_len(t_printf **bag, int len)
{
	int		diff;

	diff = 0;
	if ((*bag)->precision > len)
	{
		diff = (*bag)->precision - len;
		putzeros(diff);
		(*bag)->size += diff;
	}
}

void		putnbr_width_zeros(t_printf **bag, int len,
								int neg, t_intmax number)
{
	int		diff;

	diff = 0;
	if ((*bag)->precision > len)
		diff = (*bag)->width - (*bag)->precision - neg;
	else
		diff = (*bag)->width - len - neg;
	if (diff >= 0)
	{
		if ((*bag)->precision != -1)
			putspaces(diff);
		else
		{
			putnbr_print_plus_space2(neg, number, bag);
			putzeros(diff);
		}
		(*bag)->size += diff;
	}
}
