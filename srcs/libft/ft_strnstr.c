/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:02:49 by pcuadrad          #+#    #+#             */
/*   Updated: 2019/11/15 10:41:50 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*str;
	const char	*set;
	size_t		size;

	if (!*needle)
		return ((char*)haystack);
	while (*haystack && len > 0)
	{
		str = haystack;
		set = needle;
		size = len;
		while (*str == *set && *set && size--)
		{
			str++;
			set++;
		}
		if (*set == '\0')
			return ((char*)haystack);
		haystack++;
		--len;
	}
	return (NULL);
}
