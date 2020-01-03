/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_plus_space.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 14:31:32 by pcuadrad          #+#    #+#             */
/*   Updated: 2019/12/04 14:36:46 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		putnbr_plus_space_bonus(t_intmax number, t_printf **bag)
{
	int		dev;

	dev = (number < 0 || (*bag)->plus || (*bag)->space) ? 1 : 0;
	if (dev)
	{
		if (number < 0)
			ft_putchar('-');
		else if ((*bag)->plus && number >= 0)
			ft_putchar('+');
		else if ((*bag)->space && number >= 0)
			ft_putchar(' ');
		(*bag)->size += 1;
	}
	return (dev);
}

int		putnbr_plus_space2_bonus(t_intmax number, t_printf **bag)
{
	int		dev;

	dev = (((*bag)->plus && number >= 0)
			|| ((*bag)->space && number >= 0)) ? 1 : 0;
	return (dev);
}

int		putnbr_plus_space3_bonus(t_intmax number, t_printf **bag)
{
	int		dev;

	dev = (number < 0 || (*bag)->plus || (*bag)->space) ? 1 : 0;
	return (dev);
}

void	putnbr_print_plus_space(int symbol, t_intmax number, t_printf **bag)
{
	if (symbol)
	{
		if ((*bag)->plus && number >= 0)
			ft_putchar('+');
		else if ((*bag)->space && number >= 0)
			ft_putchar(' ');
		(*bag)->size += 1;
	}
}

void	putnbr_print_plus_space2(int symbol, t_intmax number, t_printf **bag)
{
	if (symbol)
	{
		if (number < 0)
			ft_putchar('-');
		else if ((*bag)->plus)
			ft_putchar('+');
		else if ((*bag)->space)
			ft_putchar(' ');
		(*bag)->size += 1;
	}
}
