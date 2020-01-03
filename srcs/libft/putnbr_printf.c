/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 14:31:12 by pcuadrad          #+#    #+#             */
/*   Updated: 2019/12/04 14:36:57 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		putnbr_printf_1minus(t_printf **bag)
{
	t_intmax		number;
	int				len;
	int				symbol;

	if ((number = putnbr_check_zero(bag)) == 0 && (*bag)->precision != -1)
		return ;
	len = ft_nbrlenprec(number);
	symbol = putnbr_plus_space_bonus(number, bag);
	putnbr_prec_len(bag, len);
	ft_putnbrprintfprec(number, bag);
	putnbr_width_prec(bag, len, symbol);
}

static void		putnbr_printf_0minus(t_printf **bag)
{
	int				diff;
	t_intmax		number;
	int				symbol;

	if ((number = putnbr_check_zero(bag)) == 0 && (*bag)->precision != -1)
		return ;
	symbol = putnbr_plus_space2_bonus(number, bag);
	diff = ft_nbrlen(number) + symbol;
	if ((*bag)->width > diff)
	{
		diff = (*bag)->width - diff;
		putspaces(diff);
		(*bag)->size += diff;
	}
	putnbr_print_plus_space(symbol, number, bag);
	ft_putnbrprintf(number, bag);
}

static void		putnbr_printf_zeros(t_printf **bag)
{
	t_intmax		number;
	int				neg;
	int				len;

	if ((number = putnbr_check_zero(bag)) == 0 && (*bag)->precision != -1)
		return ;
	len = ft_nbrlenprec(number);
	neg = putnbr_plus_space3_bonus(number, bag);
	if ((*bag)->width > len)
		putnbr_width_zeros(bag, len, neg, number);
	if (neg && ((*bag)->precision != -1 || len >= (*bag)->width))
		putnbr_print_plus_space2(neg, number, bag);
	putnbr_prec_len(bag, len);
	ft_putnbrprintfprec(number, bag);
}

static void		putnbr_printf_precision(t_printf **bag)
{
	int				len;
	t_intmax		number;
	int				symbol;

	if ((number = putnbr_check_zero(bag)) == 0 && (*bag)->precision != -1)
		return ;
	len = ft_nbrlenprec(number);
	symbol = putnbr_plus_space3_bonus(number, bag);
	putnbr_width_prec(bag, len, symbol);
	putnbr_print_plus_space2(symbol, number, bag);
	putnbr_prec_len(bag, len);
	ft_putnbrprintfprec(number, bag);
}

void			putnbr_printf(t_printf **bag)
{
	if ((*bag)->minus == 1)
		putnbr_printf_1minus(bag);
	else if ((*bag)->minus == 0)
	{
		if ((*bag)->zero == 1)
			putnbr_printf_zeros(bag);
		else if ((*bag)->precision > -1)
			putnbr_printf_precision(bag);
		else
			putnbr_printf_0minus(bag);
	}
}
