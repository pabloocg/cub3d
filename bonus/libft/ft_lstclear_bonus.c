/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:39:26 by pcuadrad          #+#    #+#             */
/*   Updated: 2019/11/08 11:52:05 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *tmp;

	if (!*lst)
		return ;
	while (*lst)
	{
		tmp = *lst;
		(*del)((*lst)->content);
		free(*lst);
		*lst = tmp->next;
	}
	*lst = NULL;
}
