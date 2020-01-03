/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:57:49 by pcuadrad          #+#    #+#             */
/*   Updated: 2019/11/08 15:22:07 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*tmp;

	new_list = NULL;
	while (lst)
	{
		if (!(tmp = ft_lstnew((*f)(lst->content))))
			ft_lstdelone(lst, del);
		else
			ft_lstadd_back(&new_list, tmp);
		lst = lst->next;
	}
	return (new_list);
}
