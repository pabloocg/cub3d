/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:02:12 by pcuadrad          #+#    #+#             */
/*   Updated: 2019/11/13 16:27:33 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*str_string;
	int				i;
	int				j;

	str_string = (char*)s;
	i = 0;
	j = -1;
	while (str_string[i])
	{
		if (str_string[i] == c)
			j = i;
		i++;
	}
	if (str_string[i] == c)
		return (str_string + i);
	if (j >= 0)
		return (str_string + j);
	return (NULL);
}
