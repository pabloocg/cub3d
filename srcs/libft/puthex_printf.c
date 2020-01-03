/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthex_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 17:49:47 by pcuadrad          #+#    #+#             */
/*   Updated: 2019/12/04 14:36:33 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		puthex_printf_1minus(t_printf **bag)
{
	t_intmax		number;
	int				len;
	int				hash;

	if ((number = putnbr_check_zero(bag)) == 0 && (*bag)->precision != -1)
		return ;
	hash = puthex_hash(bag);
	if (hash == 2)
		printf_0x(bag);
	len = ft_nbrhexlen(number);
	putnbr_prec_len(bag, len);
	printf_hex(number, bag);
	putnbr_width_prec(bag, len, hash);
}

static void		puthex_printf_0minus(t_printf **bag)
{
	int				len;
	t_intmax		number;
	int				diff;
	int				hash;

	if ((number = putnbr_check_zero(bag)) == 0 && (*bag)->precision != -1)
		return ;
	hash = puthex_hash(bag);
	len = ft_nbrhexlen(number) + hash;
	if ((*bag)->width > len)
	{
		diff = (*bag)->width - len;
		putspaces(diff);
		(*bag)->size += diff;
	}
	if (hash == 2)
		printf_0x(bag);
	printf_hex(number, bag);
}

static void		puthex_printf_zeros(t_printf **bag)
{
	t_intmax		number;
	int				len;
	int				hash;

	if ((number = putnbr_check_zero(bag)) == 0 && (*bag)->precision != -1)
		return ;
	len = ft_nbrhexlen(number);
	hash = puthex_hash(bag);
	if ((*bag)->width > len)
		putnbr_width_zeros(bag, len, hash, 0);
	if (hash == 2)
		printf_0x(bag);
	putnbr_prec_len(bag, len);
	printf_hex(number, bag);
}

static void		puthex_printf_precision(t_printf **bag)
{
	int				len;
	unsigned int	number;
	int				hash;

	if ((number = putnbr_check_zero(bag)) == 0 && (*bag)->precision != -1)
		return ;
	len = ft_nbrhexlen(number);
	hash = puthex_hash(bag);
	putnbr_width_prec(bag, len, hash);
	if (hash == 2)
		printf_0x(bag);
	putnbr_prec_len(bag, len);
	printf_hex(number, bag);
}

void			puthex_printf(t_printf **bag)
{
	if ((*bag)->minus == 1)
		puthex_printf_1minus(bag);
	else if ((*bag)->minus == 0)
	{
		if ((*bag)->zero == 1)
			puthex_printf_zeros(bag);
		else if ((*bag)->precision > -1)
			puthex_printf_precision(bag);
		else
			puthex_printf_0minus(bag);
	}
}
