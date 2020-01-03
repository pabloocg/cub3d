/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putunsigned_printf_aux.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 16:22:40 by pcuadrad          #+#    #+#             */
/*   Updated: 2019/12/04 14:37:11 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_intmax		putunsigned_check_zero(t_printf **bag)
{
	t_intmax	number;

	if ((*bag)->mask == 'l')
		number = (long int)va_arg((*bag)->argv, long int);
	else if ((*bag)->mask == 'd')
		number = (long long int)va_arg((*bag)->argv, long long int);
	else if ((*bag)->mask == 'h')
		number = (short int)va_arg((*bag)->argv, int);
	else if ((*bag)->mask == 'D')
		number = (signed char)va_arg((*bag)->argv, int);
	else
		number = (unsigned int)va_arg((*bag)->argv, int);
	if (number == 0 && (*bag)->precision != -1)
	{
		putnbr_print_0(bag);
		return (0);
	}
	number = (t_intmax)number;
	return (number);
}

void			ft_putnbru(unsigned int nb, t_printf **bag)
{
	if (nb >= 10)
		ft_putnbru(nb / 10, bag);
	ft_putchar(nb % 10 + '0');
	(*bag)->size += 1;
}
