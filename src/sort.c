/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:00:40 by ialdidi           #+#    #+#             */
/*   Updated: 2024/03/26 11:29:10 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	first_or_second_part(t_list *lst, int target, int size)
{
	while (size--)
	{
		if (lst->index == target)
		{
			return (0);
		}
		lst = lst->next;
	}
	return (1);
}

void	rotate_and_push(t_object *obj,
	void (*rotate_func)(t_list **, t_list **),
		void (*rotate_func2)(t_list **, t_list **), int *target)
{
	int	n;

	n = 0;
	while (obj->stack_b)
	{
		rotate_func(NULL, &obj->stack_b);
		if (obj->stack_b->index == *target)
		{
			push(&obj->stack_b, &obj->stack_a, "pa");
			*target -= 1;
			break ;
		}
		n++;
	}
	while (n--)
	{
		rotate_func2(NULL, &obj->stack_b);
		if (obj->stack_b->index == *target)
		{
			push(&obj->stack_b, &obj->stack_a, "pa");
			*target -= 1;
		}
	}
}

void	pull_chunk(t_object *obj, int *size)
{
	int			target;
	int			tmp;

	target = obj->stack_a->index - 1;
	if (obj->stack_b->index == target
		|| ft_lstlast(obj->stack_b)->index == target
		|| obj->stack_b->next->index == target)
	{
		if (obj->stack_b->next && obj->stack_b->next->index == target)
			swap(NULL, &obj->stack_b);
		else if (obj->stack_b->index != target)
			reverse_rotate(NULL, &obj->stack_b);
		push(&obj->stack_b, &obj->stack_a, "pa");
		*size -= 1;
	}
	else if (ft_lstlast(obj->stack_a)->index == obj->max)
	{
		push(&obj->stack_b, &obj->stack_a, "pa");
		rotate(&obj->stack_a, NULL);
	}
	else
	{
		tmp = *size / 2;
		if (!first_or_second_part(obj->stack_b, target, *size / 2))
			rotate_and_push(obj, rotate, reverse_rotate, &target);
		else
			rotate_and_push(obj, reverse_rotate, rotate, &target);
	}
}

int	push_chunk(t_object *obj, int s)
{
	static int	i;
	static int	pushed;

	if (obj->stack_a->index <= s + pushed)
	{
		push(&obj->stack_a, &obj->stack_b, "pb");
		if (obj->stack_b->index <= pushed + (s / 2))
			rotate(NULL, &obj->stack_b);
		i++;
	}
	else
		rotate(&obj->stack_a, NULL);
	if (i == s)
	{
		pushed += i;
		i = 0;
		return (s);
	}
	return (0);
}

void	sort(t_object *obj)
{
	int		size;
	int		tmp;

	size = is_sorted(obj->stack_a);
	if (!size)
		return ;
	tmp = size;
	while (size > 3)
		size -= push_chunk(obj, size / 3);
	return ;
	sort_three(obj);
	obj->max = *(int *)(ft_lstlast(obj->stack_a)->content);
	size = tmp - 3;
	while (obj->stack_b)
		pull_chunk(obj, &size);
}
