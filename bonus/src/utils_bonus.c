/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:52:09 by ialdidi           #+#    #+#             */
/*   Updated: 2024/03/25 18:18:45 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

int	is_sorted(t_list *lst)
{
	int	num;
	int	is_sorted;

	is_sorted = 1;
	num = 0;
	while (lst)
	{
		if (lst->index < num)
			is_sorted = 0;
		num++;
		lst = lst->next;
	}
	return (num * (is_sorted == 0));
}

void	exiter(void)
{
	ft_printf("Error\n");
	exit(1);
}
