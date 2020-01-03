/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:50:37 by pcuadrad          #+#    #+#             */
/*   Updated: 2019/11/13 10:19:49 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*srcstr;
	unsigned char		*dststr;

	dststr = (unsigned char*)dst;
	srcstr = (unsigned char*)src;
	if (dststr == srcstr || !n)
		return (dst);
	while (n-- > 0)
		*dststr++ = *srcstr++;
	return (dst);
}
