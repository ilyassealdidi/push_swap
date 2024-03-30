/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:41:22 by ialdidi           #+#    #+#             */
/*   Updated: 2024/03/30 00:18:53 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
//TODO: Make a folder for instructions, contains the files (push, swap, rotate, reverse_rotate) 
int	main(int ac, char **av)
{
	t_object	obj;

	if (ac < 2)
		return (ft_printf("Invalid number of arguments"), EXIT_FAILURE);
	ft_memset(&obj, 0, sizeof(obj));
	if (!stack_init(&obj, av + 1))
		exiter();
	print_stacks(obj);
	//sort(&obj);
	return (EXIT_SUCCESS);
}
