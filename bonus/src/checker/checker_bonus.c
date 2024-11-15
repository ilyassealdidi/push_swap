/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 12:38:04 by ialdidi           #+#    #+#             */
/*   Updated: 2024/04/02 18:37:44 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap_bonus.h"

static void	execute_instruction(t_object *obj, char *ins)
{
	int			i;
	static char	*arr[] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra",
		"rrb", "rrr"};
	static void	(*func[])(t_object *) = {sa, sb, ss, pa, pb, ra, rb, rr, rra,
		rrb, rrr};

	i = -1;
	while (++i < 11)
	{
		if (ft_strncmp(ins, arr[i], ft_strlen(ins) - 1) == 0)
		{
			func[i](obj);
			return ;
		}
	}
}

static int	is_instruction(char *ins)
{
	int			i;
	static char	*arr[] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra",
		"rrb", "rrr"};

	if (*ins == '\n')
		return (0);
	i = -1;
	while (++i < 11)
	{
		if (ft_strncmp(ins, arr[i], ft_strlen(ins) - 1) == 0)
			return (1);
	}
	return (0);
}

static int	instructions_init(t_object *obj)
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
	return (1);
}

void	apply_instructions(t_object *obj)
{
	t_list	*lst;

	lst = obj->instructions;
	while (lst)
	{
		execute_instruction(obj, lst->content);
		lst = lst->next;
	}
}

int	check_sort(t_object *obj)
{
	int	status;

	if (!instructions_init(obj))
	{
		destroy_object(obj);
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	apply_instructions(obj);
	status = (obj->stack_b.length == 0 && is_sorted(obj->stack_a.list));
	destroy_object(obj);
	return (status);
}
