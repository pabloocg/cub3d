/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putspaces.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:34:35 by pcuadrad          #+#    #+#             */
/*   Updated: 2019/12/04 14:37:03 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	putspaces(int nspaces)
{
	if (nspaces > 0)
		while (nspaces)
		{
			ft_putchar(' ');
			nspaces--;
		}
}
