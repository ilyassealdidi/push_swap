/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:44:06 by ialdidi           #+#    #+#             */
/*   Updated: 2024/03/18 01:22:52 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_swap_top(t_list **lst)
{
	t_list	*item;
	t_list	*tmp;

	if (ft_lstsize(*lst) <= 1)
		return (0);
	tmp = (*lst)->next;
	item = tmp->next;
	(*lst)->next = item;
	tmp->next = *lst;
	*lst = tmp;
	return (1);
}

void	swap(t_list **stack_a, t_list **stack_b)
{
	if (stack_a && ft_swap_top(stack_a))
		ft_printf("sa\n");
	if (stack_b && ft_swap_top(stack_b))
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

void	rotate(t_list **stack_a, t_list **stack_b)
{
	t_list	*item;
	t_list	*last;

	if (stack_a && *stack_a)
	{
		item = (*stack_a)->next;
		last = ft_lstlast(*stack_a);
		(*stack_a)->next = NULL;
		last->next = *stack_a;
		*stack_a = item;
		ft_printf("ra");
	}
	if (stack_b && *stack_b)
	{
		item = (*stack_b)->next;
		last = ft_lstlast(*stack_b);
		(*stack_b)->next = NULL;
		last->next = *stack_b;
		*stack_b = item;
		ft_printf("rb");
	}
}

void	reverse_rotate(t_list **stack_a, t_list **stack_b)
{
	if (stack_a && ft_lstshift_down(stack_a))
		ft_printf("rra");
	if (stack_b && ft_lstshift_down(stack_b))
		ft_printf("rrb");
}
