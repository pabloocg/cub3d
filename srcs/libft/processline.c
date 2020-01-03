/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 13:49:40 by pcuadrad          #+#    #+#             */
/*   Updated: 2019/12/04 14:36:17 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Funcion que procesa la linea
**	Si se encuentra un porcentaje llama a otra funcion que parseara los valores.
**	Si no encuentra porcentaje imprime el caracter.
**	En bag->size vamos sumando los caracteres qe imprimimos.
*/

void		processline(t_printf **bag)
{
	int			j;

	j = -1;
	while ((*bag)->format[++j])
	{
		if ((*bag)->format[j] == '%')
		{
			reinitialize(bag);
			j += destructor((*bag)->format + j + 1, bag);
		}
		else
			(*bag)->size += write(1, &(*bag)->format[j], 1);
	}
}
