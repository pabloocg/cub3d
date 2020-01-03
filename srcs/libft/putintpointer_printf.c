/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putintpointer_printf.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 19:22:18 by pcuadrad          #+#    #+#             */
/*   Updated: 2019/12/04 14:36:36 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	putintpointer_printf(t_printf **bag)
{
	*va_arg((*bag)->argv, int*) = (*bag)->size;
}
