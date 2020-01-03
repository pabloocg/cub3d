/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 14:25:40 by pcuadrad          #+#    #+#             */
/*   Updated: 2019/12/04 14:37:44 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnstr(t_printf **bag, char *str)
{
	int		widthprecision;
	int		i;

	i = -1;
	if (!str)
		str = "(null)";
	widthprecision = (*bag)->precision;
	if (widthprecision != -1)
		while (str[++i] && widthprecision > 0)
		{
			(*bag)->size++;
			widthprecision--;
			ft_putchar(str[i]);
		}
	else
		while (str[++i])
		{
			(*bag)->size++;
			widthprecision--;
			ft_putchar(str[i]);
		}
	return (i);
}
