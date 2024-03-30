/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 14:09:37 by ialdidi           #+#    #+#             */
/*   Updated: 2024/03/30 14:27:32 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	rotate(t_list **stack)
{
	t_list	*item;
	t_list	*last;

	if (stack && *stack)
	{
		item = (*stack)->next;
		if (!item)
			return ;
		last = ft_lstlast(*stack);
		(*stack)->next = NULL;
		last->next = *stack;
		*stack = item;
	}
}

void	ra(t_object *obj)
{
	rotate(&obj->stack_a.list);
	ft_printf("%s\n", "ra");
}

void	rb(t_object *obj)
{
	rotate(&obj->stack_b.list);
	ft_printf("%s\n", "rb");
}

void	rr(t_object *obj)
{
	rotate(&obj->stack_a.list);
	rotate(&obj->stack_b.list);
	ft_printf("%s\n", "rr");
}
