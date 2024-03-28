/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:00:40 by ialdidi           #+#    #+#             */
/*   Updated: 2024/03/28 21:02:26 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_object *obj)
{
	if (is_sorted(obj->stack_a) == 0)
		return ;
	if (obj->stack_a->index < obj->stack_a->next->index)
		reverse_rotate(&obj->stack_a, NULL);
	else if (obj->stack_a->index > obj->stack_a->next->index
		&& obj->stack_a->index > obj->stack_a->next->next->index)
		rotate(&obj->stack_a, NULL);
	if (obj->stack_a->index > obj->stack_a->next->index)
		swap(&obj->stack_a, NULL);
	obj->max = obj->stack_a->next->next->index;
}

void	pull_chunk(t_object *obj, int *size)
{
	int			target;
	int			last_a;
	int			last_b;

	target = obj->stack_a->index - 1;
	last_a = ft_lstlast(obj->stack_a)->index;
	last_b = ft_lstlast(obj->stack_b)->index;
	if (obj->stack_b->index == target || last_b == target)
	{
		if (obj->stack_b->index != target)
			reverse_rotate(NULL, &obj->stack_b);
		push(&obj->stack_b, &obj->stack_a, "pa");
		*size -= 1;
	}
	else if (last_a == target)
		reverse_rotate(&obj->stack_a, NULL);
	else if (last_a == obj->max || obj->stack_b->index > target
		|| last_b > last_a)
	{
		if (last_b > last_a)
			reverse_rotate(NULL, &obj->stack_b);
		push(&obj->stack_b, &obj->stack_a, "pa");
		rotate(&obj->stack_a, NULL);
		*size -= 1;
	}
	else
	{
		if (!first_or_second_part(obj->stack_b, target, *size / 2))
			rotate(NULL, &obj->stack_b);
		else
			reverse_rotate(NULL, &obj->stack_b);
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
	sort_three(obj);
	size = tmp - 3;
	while (obj->stack_b)
		pull_chunk(obj, &size);
	while (obj->stack_a->index != 1)
		reverse_rotate(&obj->stack_a, NULL);
}
