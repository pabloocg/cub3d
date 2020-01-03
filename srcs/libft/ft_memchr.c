/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:36:10 by marvin            #+#    #+#             */
/*   Updated: 2019/11/13 10:33:20 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*str_string;

	str_string = (unsigned char*)str;
	while (n > 0)
	{
		if (*str_string == (unsigned char)c)
			return ((void*)str_string);
		str_string++;
		n--;
	}
	return (NULL);
}
