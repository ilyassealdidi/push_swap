/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:41:22 by ialdidi           #+#    #+#             */
/*   Updated: 2024/03/31 20:24:08 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_object	obj;

	if (ac < 2)
		return (ft_printf("Invalid number of arguments"), EXIT_FAILURE);
	obj = (t_object){};
	if (!stack_init(&obj, av + 1))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	sort(&obj);
	ft_lstclear(&obj.stack_a.list, free);
	return (EXIT_SUCCESS);
}
