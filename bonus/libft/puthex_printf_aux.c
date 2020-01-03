/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthex_printf_aux.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 18:52:45 by pcuadrad          #+#    #+#             */
/*   Updated: 2019/12/04 14:36:30 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		printf_hex(t_intmax number, t_printf **bag)
{
	if ((*bag)->conversion == 'x')
		ft_putnbr_base(number, "0123456789abcdef", bag);
	else
		ft_putnbr_base(number, "0123456789ABCDEF", bag);
}

int			puthex_hash(t_printf **bag)
{
	if ((*bag)->hash)
		return (2);
	return (0);
}

size_t		ft_nbrhexlen(t_intmax num)
{
	size_t					size;
	unsigned long long int	nb;

	size = 0;
	nb = num;
	if (num == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 16;
		size++;
	}
	return (size);
}
