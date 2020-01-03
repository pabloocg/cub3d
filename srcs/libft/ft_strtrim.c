/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:05:07 by pcuadrad          #+#    #+#             */
/*   Updated: 2019/11/13 16:39:07 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		isinset(char c, char const *charset)
{
	int		i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	unsigned int		start;
	unsigned int		end;

	if (!s1)
		return (NULL);
	start = 0;
	end = (int)ft_strlen(s1) - 1;
	while (isinset(s1[start], set) && s1[start])
		start++;
	if (s1[start] == '\0')
		return (ft_strdup(""));
	while (isinset(s1[end], set) && s1[end])
		end--;
	return (ft_substr(s1, start, (end - start + 1)));
}
