/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putmemory_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 19:20:10 by pcuadrad          #+#    #+#             */
/*   Updated: 2019/12/04 14:36:43 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		putmemory_printf_1minus(t_printf **bag)
{
	t_uintptr		number;
	int				len;

	if ((number = (t_uintptr)va_arg((*bag)->argv, void*)) == 0)
	{
		putmemory_nill(bag);
		return ;
	}
	len = ft_nbrmemlen(number);
	len += ((*bag)->precision > len) ? 0 : 2;
	printf_0x(bag);
	putnbr_prec_len(bag, len);
	ft_putnbr_base_mem(number, HEX, bag);
	(*bag)->precision += ((*bag)->precision > len) ? 2 : 0;
	putnbr_width_prec(bag, len, 0);
}

static void		putmemory_printf_0minus(t_printf **bag)
{
	int				len;
	t_uintptr		number;
	int				diff;

	if ((number = (t_uintptr)va_arg((*bag)->argv, void*)) == 0)
	{
		putmemory_nill(bag);
		return ;
	}
	len = ft_nbrmemlen(number) + 2;
	if ((*bag)->width > len)
	{
		diff = (*bag)->width - len;
		putspaces(diff);
		(*bag)->size += diff;
	}
	printf_0x(bag);
	ft_putnbr_base_mem(number, HEX, bag);
}

static void		putmemory_printf_zeros(t_printf **bag)
{
	t_uintptr		number;
	int				len;

	if ((number = (t_uintptr)va_arg((*bag)->argv, void*)) == 0)
	{
		putmemory_nill(bag);
		return ;
	}
	len = ft_nbrmemlen(number);
	printf_0x(bag);
	len += ((*bag)->precision > len) ? 0 : 2;
	if ((*bag)->width > len)
		putnbr_width_zeros(bag, len, 0, 0);
	putnbr_prec_len(bag, len);
	ft_putnbr_base_mem(number, HEX, bag);
}

static void		putmemory_printf_precision(t_printf **bag)
{
	int				len;
	t_uintptr		number;

	if ((number = (t_uintptr)va_arg((*bag)->argv, void*)) == 0)
	{
		putmemory_nill(bag);
		return ;
	}
	len = ft_nbrmemlen(number) + 2;
	putnbr_width_prec(bag, len, 0);
	printf_0x(bag);
	putnbr_prec_len(bag, len);
	ft_putnbr_base_mem(number, HEX, bag);
}

void			putmemory_printf(t_printf **bag)
{
	if ((*bag)->minus == 1)
		putmemory_printf_1minus(bag);
	else if ((*bag)->minus == 0)
	{
		if ((*bag)->zero == 1)
			putmemory_printf_zeros(bag);
		else if ((*bag)->precision > -1)
			putmemory_printf_precision(bag);
		else
			putmemory_printf_0minus(bag);
	}
}
