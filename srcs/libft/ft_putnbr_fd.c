/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 20:23:26 by marvin            #+#    #+#             */
/*   Updated: 2019/11/12 20:03:56 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	i;

	i = (unsigned int)n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		i *= -1;
	}
	if (i >= 10)
		ft_putnbr_fd((i / 10), fd);
	ft_putchar_fd((char)(i % 10 + '0'), fd);
}
