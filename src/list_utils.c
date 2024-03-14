/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 09:26:25 by ialdidi           #+#    #+#             */
/*   Updated: 2024/03/14 13:41:40 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static t_list	*ft_lstgetitem(t_list *lst, void *content)
{
	while (lst != NULL)
	{
		if (*(long *)(lst->content) == *(long *)content)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

int	ft_lstappenditem(t_list **lst, void *content)
{
	t_list	*item;

	item = ft_lstnew(content);
	if (!item)
		return (0);
	if (!lst)
		*lst = item;
	else if (!ft_lstgetitem(*lst, content))
		return (ft_lstadd_back(lst, item), 1);
	return (free(item), 0);
}

int	ft_lstshift_down(t_list **lst)
{
	t_list	*item;
	t_list	*tmp;

	if (ft_lstsize(*lst) <= 1)
		return (0);
	item = *lst;
	while (item)
	{
		if (!item->next->next)
		{
			tmp = item->next;
			item->next = NULL;
		}
		item = item->next;
	}
	tmp->next = *lst;
	*lst = tmp;
	return (1);
}
