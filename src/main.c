/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:41:22 by ialdidi           #+#    #+#             */
/*   Updated: 2024/03/25 18:26:55 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_list(t_list	*list, char cs);
void	print_stacks(t_object obj);

int	main(int ac, char **av)
{
	t_object	obj;

	if (ac >= 2)
	{
		list_init(&obj, av + 1);
		//print_stacks(obj);
		sort(&obj);
		//print_stacks(obj);
	}
	else
		ft_printf("Invalid number of arguments");
	return (EXIT_SUCCESS);
}

// TODO: to be deleted
void	print_list(t_list	*list, char stack)
{
	if (list)
	{
		ft_printf("\n\n");
		ft_printf("Stack %c : (%d numbers)\n__________________________\n\n",
			stack, ft_lstsize(list));
		while (list)
		{
			ft_printf("Index : %d \t Num : %d\n",
				list->index, *(int *)(list->content));
			list = list->next;
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
