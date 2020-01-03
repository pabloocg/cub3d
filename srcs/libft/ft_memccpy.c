/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:08:30 by pcuadrad          #+#    #+#             */
/*   Updated: 2019/11/12 18:21:02 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*srcstr;
	unsigned char		*dststr;
	size_t				i;

	dststr = (unsigned char*)dst;
	srcstr = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		dststr[i] = srcstr[i];
		if (dststr[i] == (unsigned char)c)
			return ((void*)dststr + i + 1);
		i++;
	}
	return (NULL);
}
