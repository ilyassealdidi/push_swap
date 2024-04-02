/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:00:40 by ialdidi           #+#    #+#             */
/*   Updated: 2024/04/02 15:54:51 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	sort_three(t_object *obj)
{
	if (is_sorted(obj->stack_a.list))
		return ;
	if (get_item_index(obj->stack_a.list)
		< get_item_index(obj->stack_a.list->next))
		rra(obj);
	else if (get_item_index(obj->stack_a.list)
		> get_item_index(obj->stack_a.list->next->next))
		ra(obj);
	if (get_item_index(obj->stack_a.list)
		> get_item_index(obj->stack_a.list->next))
		sa(obj);
}

static void	sort_rest(t_object *obj)
{
	int	min;

	min = (obj->max > 5) * (obj->max - obj->stack_a.length) + 1;
	while (obj->stack_a.length != 3)
	{
		if (is_sorted(obj->stack_a.list))
			return ;
		if (get_first_index(obj->stack_a) == min)
		{
			pb(obj);
			min++;
		}
		else if (initial_or_second_part(obj->stack_a, min) == 1)
			ra(obj);
		else if (initial_or_second_part(obj->stack_a, min) == 2)
			rra(obj);
	}
	sort_three(obj);
}

void	pull_chunk(t_object *obj)
{
	int			target;
	int			last_a;
	int			last_b;

	target = get_first_index(obj->stack_a) - 1;
	last_a = get_last_index(obj->stack_a);
	last_b = get_last_index(obj->stack_b);
	if (get_first_index(obj->stack_b) == target)
		pa(obj);
	else if (last_b == target)
		(rrb(obj), pa(obj));
	else if (last_a == target)
		rra(obj);
	else if (last_a == obj->max)
		(pa(obj), ra(obj));
	else if (last_b > last_a)
		(rrb(obj), pa(obj), ra(obj));
	else if (initial_or_second_part(obj->stack_b, target) == 1)
		rb(obj);
	else
		rrb(obj);
}

int	push_chunk(t_object *obj, int s)
{
	static int	i;
	static int	pushed;

	if (get_first_index(obj->stack_a) <= s + pushed)
	{
		pb(obj);
		if (get_first_index(obj->stack_b) <= pushed + (s / 2))
			rb(obj);
		i++;
	}
	else
		ra(obj);
	if (i == s)
		return (pushed += s, i = 0, s);
	return (0);
}

void	sort(t_object *obj)
{
	int		size;
	int		pushed;

	if (is_sorted(obj->stack_a.list))
		return ;
	size = obj->stack_a.length;
	pushed = size;
	while (obj->stack_a.length > 5 || pushed == 0)
	{
		pushed = push_chunk(obj, size / 3);
		size -= pushed;
	}
	sort_rest(obj);
	while (obj->stack_b.length > 0)
		pull_chunk(obj);
	while (get_first_index(obj->stack_a) != 1)
		rra(obj);
}
