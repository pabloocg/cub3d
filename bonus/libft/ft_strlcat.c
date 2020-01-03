/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:38:47 by pcuadrad          #+#    #+#             */
/*   Updated: 2019/11/12 19:35:38 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	cont;

	cont = 0;
	j = ft_strlen(dest);
	i = ft_strlen(src);
	if (size >= j)
		cont = i + j;
	else
		return (i + size);
	i = 0;
	while (src[i] && (i + j) < (size - 1) && dest != src)
	{
		dest[i + j] = (char)src[i];
		i++;
	}
	dest[i + j] = '\0';
	return (cont);
}
