/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_printf_aux2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 15:33:35 by pcuadrad          #+#    #+#             */
/*   Updated: 2019/12/04 14:36:52 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	putnbr_print_0_aux(t_printf **bag, int *diff)
{
	if ((*bag)->precision > 0)
	{
		*diff = (*bag)->precision;
		putzeros(*diff);
		(*bag)->size += *diff;
	}
}

void		putnbr_print_0(t_printf **bag)
{
	int		diff;
	int		symbol;

	diff = 0;
	if ((*bag)->minus == 1)
	{
		symbol = putnbr_plus_space_bonus(0, bag);
		putnbr_print_0_aux(bag, &diff);
		putnbr_width_prec(bag, diff, symbol);
	}
	else
	{
		symbol = putnbr_plus_space2_bonus(0, bag);
		putnbr_width_prec(bag, diff, symbol);
		putnbr_print_plus_space(symbol, 0, bag);
		putnbr_print_0_aux(bag, &diff);
	}
}

void		ft_putnbrprintfprec(t_intmax nb, t_printf **bag)
{
	unsigned long long int	i;

	i = nb;
	if (nb < 0)
		i = i * -1;
	if (i >= 10)
		ft_putnbrprintfprec(i / 10, bag);
	ft_putchar(i % 10 + '0');
	(*bag)->size += 1;
}

void		ft_putnbrprintf(t_intmax nb, t_printf **bag)
{
	unsigned long long int	i;

	i = nb;
	if (nb < 0)
	{
		ft_putchar('-');
		i = i * -1;
		(*bag)->size += 1;
	}
	if (i >= 10)
		ft_putnbrprintf(i / 10, bag);
	ft_putchar(i % 10 + '0');
	(*bag)->size += 1;
}

void		ft_putnbr_base(t_intmax nb, char *str, t_printf **bag)
{
	unsigned long long int	nbr;

	nbr = nb;
	if (nbr >= 16)
		ft_putnbr_base(nbr / 16, str, bag);
	ft_putchar(str[nbr % 16]);
	(*bag)->size++;
}
