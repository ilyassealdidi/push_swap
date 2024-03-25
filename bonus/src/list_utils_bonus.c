/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 09:26:25 by ialdidi           #+#    #+#             */
/*   Updated: 2024/03/25 15:39:14 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

static int	set_index(t_list *list, t_list *new)
{
	t_list	*lst;

	lst = list;
	while (lst)
	{
		if (*(int *)(new->content) > *(int *)(lst->content))
			new->index++;
		else if (*(int *)(new->content) < *(int *)(lst->content))
			lst->index++;
		else
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	ft_lstappenditem(t_list **lst, void *content)
{
	t_list	*item;

	item = ft_lstnew(content);
	if (!item)
		return (0);
	item->index = 1;
	if (!set_index(*lst, item))
		return (free(item), 0);
	if (!lst)
		*lst = item;
	else
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
