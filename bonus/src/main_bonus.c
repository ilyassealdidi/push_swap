/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:45:21 by ialdidi           #+#    #+#             */
/*   Updated: 2024/04/05 03:13:07 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

int	main(int ac, char **av)
{
	t_object	obj;

	if (ac < 2)
		return (0);
	ft_memset(&obj, 0, sizeof(obj));
	if (!stack_init(&obj, av + 1))
	{
		ft_putstr_fd("Error\n", 2);
		return (EXIT_FAILURE);
	}
	if (check_sort(&obj) == 1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (0);
}
