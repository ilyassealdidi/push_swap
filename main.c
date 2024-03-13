/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:41:22 by ialdidi           #+#    #+#             */
/*   Updated: 2024/03/13 18:34:03 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_memory(char **strs)
{
	int	i;

	if (!strs)
		return ;
	i = -1;
	while (1)
	{
		free(strs[++i]);
		if (!strs[i])
			break ;
	}
	free(strs);
}

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
	t_list		*item;

	item = NULL;
	if (ac >= 2)
	{
		list_init(&obj, av + 1);
		push(&obj.stack_a, &obj.stack_b, "pb");
		//sa(obj.stack_a);
		// pb(&obj);
		// pb(&obj);
		ft_printf("Stack a\n");
		print_list(obj.stack_a);
		ft_printf("Stack b\n");
		print_list(obj.stack_b);
	}
	else
		ft_printf("Invalid number of arguments");
	return (EXIT_SUCCESS);
}
