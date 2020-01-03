/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:31:24 by pcuadrad          #+#    #+#             */
/*   Updated: 2019/11/12 18:12:45 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		sizeint(long int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char		*num;
	int			sizenum;
	long int	nl;

	nl = n;
	sizenum = sizeint(nl);
	if (!(num = (char*)malloc(sizeof(char) * (sizenum + 1))))
		return (NULL);
	num[sizenum] = '\0';
	if (nl == 0)
	{
		num[0] = '0';
		return (num);
	}
	if (nl < 0)
	{
		nl *= -1;
		num[0] = '-';
	}
	while (nl > 0)
	{
		num[--sizenum] = (nl % 10) + '0';
		nl /= 10;
	}
	return (num);
}
