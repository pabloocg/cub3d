/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:14:31 by marvin            #+#    #+#             */
/*   Updated: 2019/11/11 10:42:26 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t i;

	i = -1;
	while (++i < n)
		if (((unsigned char*)str1)[i] != ((unsigned char*)str2)[i])
			return (((unsigned char*)str1)[i] - ((unsigned char*)str2)[i]);
	return (0);
}
