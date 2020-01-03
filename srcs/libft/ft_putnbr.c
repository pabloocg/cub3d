/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:40:12 by pcuadrad          #+#    #+#             */
/*   Updated: 2019/11/07 12:50:20 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	char			num;
	unsigned int	i;

	i = nb;
	if (nb < 0)
	{
		write(1, "-", 1);
		i = i * -1;
	}
	if (i < 10)
	{
		num = (i % 10) + '0';
		write(1, &num, 1);
	}
	if (i >= 10)
	{
		ft_putnbr(i / 10);
		ft_putnbr(i % 10);
	}
}
