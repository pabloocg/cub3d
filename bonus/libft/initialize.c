/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 13:48:20 by pcuadrad          #+#    #+#             */
/*   Updated: 2019/12/04 14:37:33 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Funcion que inicia todos los valores de la estructura.
**	Hacemos una copia de los argumentos
**	En otro parametro metemos los argumentos
**	Y por ultimo metemos en una cadena la cadena que nos pasan.
*/

t_printf	*initilialize(const char *format)
{
	t_printf	*new_bag;

	if (!(new_bag = malloc(sizeof(t_printf))))
		return (NULL);
	new_bag->format = (char *)format;
	new_bag->size = 0;
	return (new_bag);
}
