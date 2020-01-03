/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 10:10:04 by pcuadrad          #+#    #+#             */
/*   Updated: 2019/11/11 10:38:46 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_element;

	new_element = NULL;
	if (!(new_element = malloc(sizeof(t_list))))
		return (new_element);
	if (!content)
		new_element->content = NULL;
	else
		new_element->content = ft_strdup((char*)content);
	new_element->next = NULL;
	return (new_element);
}
