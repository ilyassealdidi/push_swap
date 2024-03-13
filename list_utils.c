/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 09:26:25 by ialdidi           #+#    #+#             */
/*   Updated: 2024/03/13 18:16:47 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstgetitem(t_list *lst, void *content)
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
	free(item);
	return (1);
}

int	ft_lstswap_content(t_list *item1, t_list *item2)
{
	void	*num;

	if (!item1 || item2)
		return (0);
	num = item1->content;
	item1->content = item2->content;
	item2->content = num;
	return (1);
}
