/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:52:09 by ialdidi           #+#    #+#             */
/*   Updated: 2024/03/30 18:11:13 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	initial_or_second_part(t_stack stack, int target)
{
	t_list	*list;
	t_item	*item;
	int		size;

	list = stack.list;
	size = stack.length;
	while (size--)
	{
		item = (t_item *)list->content;
		if (item->index == target)
			return (1);
		list = list->next;
	}
	return (2);
}

int	is_sorted(t_list *lst)
{
	t_item	*item;
	int		tmp;

	tmp = 0;
	while (lst)
	{
		item = (t_item *)lst->content;
		if (item->index < tmp)
			return (0);
		tmp = item->index;
		lst = lst->next;
	}
	return (1);
}



void	free_array(char **strs)
{
	int	i;

	if (!strs)
		return ;
	i = -1;
	while (1)
	{
		free(strs[++i]);
		if (!strs[i])
			break ;
	}
	free(strs);
}

void	exiter(void)
{
	ft_printf("Error\n");
	exit(1);
}
