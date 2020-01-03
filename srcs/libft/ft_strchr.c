/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:04:43 by pcuadrad          #+#    #+#             */
/*   Updated: 2019/11/12 19:03:34 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str_string;

	str_string = (char*)s;
	if (c == '\0')
	{
		while (*str_string)
			str_string++;
		return (str_string);
	}
	while (*str_string)
	{
		if (*str_string == (char)c)
			return (str_string);
		str_string++;
	}
	return (NULL);
}
