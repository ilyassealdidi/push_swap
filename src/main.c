/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:41:22 by ialdidi           #+#    #+#             */
/*   Updated: 2024/03/21 15:10:38 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	exiter(void)
{
	ft_printf("Error\n");
	exit(1);
}

void	print_list(t_list	*list)
{
	if (list)
	{	
		ft_printf("\n\n");
		ft_printf("Stack a\n__________________________\n\n");
		while(list)
		{
			ft_printf("Index : %d \t Num : %d\n", list->index, *(int *)(list->content));
			list = list->next;	
		}
		ft_printf("__________________________\n\n");
	}
}

void	print_stacks(t_object obj)
{
	print_list(obj.stack_a);
	print_list(obj.stack_b);
}

int	main(int ac, char **av)
{
	t_object	obj;

	if (ac >= 2)
	{
		list_init(&obj, av + 1);
		ft_printf("\n\n");
		push(&obj.stack_a, &obj.stack_b, "pb");
		// push(&obj.stack_a, &obj.stack_b, "pb");
		print_stacks(obj);
	}
	else
		ft_printf("Invalid number of arguments");
	return (EXIT_SUCCESS);
}
