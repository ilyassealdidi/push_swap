/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optional.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 01:04:21 by ialdidi           #+#    #+#             */
/*   Updated: 2024/03/30 00:18:31 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	print_list(t_list	*list, char stack)
{
	t_item	*item;

	if (list)
	{
		ft_printf("\n\n");
		ft_printf("Stack %c : (%d numbers)\n__________________________\n\n",
			stack, ft_lstsize(list));
		while (list)
		{
			item = (t_item *)list->content;
			ft_printf("Index : %d \t Num : %d\n", item->index, item->data);
			list = list->next;
		}
		ft_printf("__________________________\n\n");
	}
}

void	print_stacks(t_object obj)
{
	ft_printf("\n\n");
	print_list(obj.stack_a.list, 'a');
	print_list(obj.stack_b.list, 'b');
}
