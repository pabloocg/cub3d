/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destructor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 13:53:04 by pcuadrad          #+#    #+#             */
/*   Updated: 2019/12/04 14:38:25 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Funcion que llamara a varias funciones que comprobaran el formato de %
**	Recibe el caracter que haya despues del porcentaje y la mochila.
**	Devuelve la cantidad de caracteres que tiene summary
**	Con la funcion ft_strldup nos hemos almacenado toda la conversion %___;
**	La funcion check_flags verifica que flags nos han pasado
**	Y va marcando ticks en (*bag).
**	Hacer una funcion que verifique que tick tiene (*bag) ejecute funciones
**	dependiento del %s-%d-%i-%c
**	Una vez que hemos desengranado el % pasamos a la funcion executer que se
**	encargara de chequear que valores tenemos marcados y ejecutar unas
**	funciones u otras.
** printf("Zero: %d\n", (*bag)->zero);
** printf("Width: %d\n", (*bag)->width);
** printf("Plus: %d\n", (*bag)->plus);
** printf("Minus: %d\n", (*bag)->minus);
** printf("Precision: %d\n", (*bag)->precision);
** printf("Conversion: %c\n", (*bag)->conversion);
*/

int		destructor(char *format, t_printf **bag)
{
	int		size;

	(*bag)->summary = ft_strldup(format);
	size = ft_strlen((*bag)->summary);
	check_flags(bag);
	check_width(bag);
	check_precision(bag);
	check_conversion(bag);
	executer(bag);
	return (size);
}
