/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:41:22 by ialdidi           #+#    #+#             */
/*   Updated: 2024/03/14 15:41:09 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	exiter(void)
{
	ft_printf("Error\n");
	exit(1);
}

void	print_list(t_list *list)
{
	while(list)
	{
		ft_printf("%d\n", *(int *)(list->content));
		list = list->next;	
	}	
}

int	main(int ac, char **av)
{
	t_object	obj;

	if (ac >= 2)
	{
		list_init(&obj, av + 1);
		ft_printf("\n__________\n");
		ft_printf("Stack a\n");
		print_list(obj.stack_a);
		ft_printf("Stack b\n");
		print_list(obj.stack_b);
	}
	else
		ft_printf("Invalid number of arguments");
	return (EXIT_SUCCESS);
}
