/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:44:06 by ialdidi           #+#    #+#             */
/*   Updated: 2024/03/13 19:41:05 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_list(t_list *list, char *instruction)
{
	int	num;

	num = *((int *)(list->content));
	if (list->next)
	{
		*((int *)(list->content)) = *((int *)(list->next->content));
		*((int *)(list->next->content)) = num;
	}
	ft_printf("%s\n", instruction);
}

void	swap(t_list *stack_a, t_list *stack_b)
{
	if (stack_a && ft_lstswap_content(stack_a, stack_a->next))
		ft_printf("sa\n");
	if (stack_b && ft_lstswap_content(stack_b, stack_b->next))
		ft_printf("sb\n");
}

void	push(t_list **stack_from, t_list **stack_to, char *instruction)
{
	t_list	*tmp;

	if (!stack_from)
		return ;
	tmp = (*stack_from)->next;
	(*stack_from)->next = NULL;
	ft_lstadd_front(stack_to, (*stack_from));
	*stack_from = tmp;
	ft_printf("%s\n", instruction);
}

// void	rotate(t_list **stack_a, t_list **stack_b)
// {
	
// }
// void	ra(t_list **list)
// {
// 	t_list	*item;

// 	item = *list;
// 	if (item && item->next)
// 	{
// 		ft_lstadd_back(list, item);
// 		*list = (*list)->next;
// 	}
// }

// void	rb(t_list **list)
// {
// 	t_list	*item;

// 	item = *list;
// 	if (item && item->next)
// 	{
// 		ft_lstadd_back(list, item);
// 		*list = (*list)->next;
// 	}
// }

// void	rr(t_object *obj)
// {
// 	ra(&obj->stack_a);
// 	rb(&obj->stack_b);
// }

// void	rra(t_list **list)
// {
// 	t_list	*item;

// 	item = ft_lstlast(*list);
// 	if (*list && (*list)->next)
// 	{
// 		item = *list;
// 	}
// }

// void	rrb(t_list **list)
// {
// 	t_list	*item;

// 	item = ft_lstlast(*list);
// 	if (*list && (*list)->next)
// 	{
// 		item = *list;
// 	}
// }

// void	rrr(t_object *obj)
// {
// 	rra(&obj->stack_a);
// 	rrb(&obj->stack_b);
// }
