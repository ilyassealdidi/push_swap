/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:41:22 by ialdidi           #+#    #+#             */
/*   Updated: 2024/03/31 01:15:52 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
//TODO: Change the list to doubly linked list
//TODO: Find an alternative to initial_second_part
static void	print_list(t_stack stack, char stack_name)
{
	t_item	*item;

	if (stack.list)
	{
		ft_printf("\n\n");
		ft_printf("Stack %c : (%d numbers)\n__________________________\n\n",
			stack_name, stack.length);
		while (stack.list)
		{
			item = (t_item *)stack.list->content;
			ft_printf("Index : %d \t Num : %d\n", item->index, item->data);
			stack.list = stack.list->next;
		}
		ft_printf("__________________________\n\n");
	}
}

void	print_stacks(t_object obj)
{
	ft_printf("\n\n");
	print_list(obj.stack_a, 'a');
	print_list(obj.stack_b, 'b');
}

void	f(void)
{
	system("leaks push_swap");
}

int	main(int ac, char **av)
{
	t_object	obj;

	atexit(f);
	if (ac < 2)
		return (ft_printf("Invalid number of arguments"), EXIT_FAILURE);
	ft_memset(&obj, 0, sizeof(obj));
	if (!stack_init(&obj, av + 1))
	{
		ft_printf("Error\n");
		exit(1);
	}
	sort(&obj);
	ft_lstclear(&obj.stack_a.list, free);
	return (EXIT_SUCCESS);
}
