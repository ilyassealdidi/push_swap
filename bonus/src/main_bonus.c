/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:45:21 by ialdidi           #+#    #+#             */
/*   Updated: 2024/03/25 18:17:56 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	destroy_object(t_object obj)
{
	ft_lstclear(&obj.stack_a, free);
	ft_lstclear(&obj.stack_b, free);
	ft_lstclear(&obj.instructions, free);
}

int	is_instruction(char *ins)
{
	int		i;
	char	**arr;

	arr = (char *[]){"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr",
		"rra", "rrb", "rrr"};
	i = -1;
	while (++i < 11)
	{
		if (!ft_strncmp(ins, arr[i], ft_strlen(arr[i])))
			return (1);
	}
	return (0);
}

void	sort_check(t_object *obj, t_list *ins)
{
	//apply_instructions(obj, ins);
	if (is_sorted(obj->stack_a) == 0 && !obj->stack_b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	destroy_object(*obj);
	exit(0);
}

int	instructions_init(t_object *obj)
{
	char	*line;
	t_list	*node;

	obj->instructions = NULL;
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		node = ft_lstnew(line);
		if (!is_instruction(line) || !node)
			return (free(line), free(node), 0);
		ft_lstadd_back(&obj->instructions, node);
	}
	if (!obj->instructions)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_object	obj;

	if (ac >= 2)
	{
		list_init(&obj, av + 1);
		if (!instructions_init(&obj))
		{
			destroy_object(obj);
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
	//	sort_check(&obj, obj.instructions);
	}
	else
		ft_printf("Invalid number of arguments");
	return (EXIT_SUCCESS);
}
