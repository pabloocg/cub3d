/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:07:43 by pcuadrad          #+#    #+#             */
/*   Updated: 2019/12/04 14:37:50 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_nbrlen(t_intmax num)
{
	size_t					size;
	unsigned long long int	nb;

	size = 0;
	nb = num;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		nb *= -1;
		size++;
	}
	while (nb > 0)
	{
		nb /= 10;
		size++;
	}
	return (size);
}

size_t		ft_nbrlenprec(t_intmax num)
{
	size_t					size;
	unsigned long long int	nb;

	size = 0;
	nb = num;
	if (num == 0)
		return (1);
	if (num < 0)
		nb *= -1;
	while (nb > 0)
	{
		nb /= 10;
		size++;
	}
	return (size);
}

size_t		ft_nbrulen(t_intmax num)
{
	size_t					size;
	unsigned long long int	nb;

	size = 0;
	nb = num;
	if (num == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 10;
		size++;
	}
	return (size);
}
