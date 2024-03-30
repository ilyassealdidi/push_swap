/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialdidi <ialdidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:30:57 by ialdidi           #+#    #+#             */
/*   Updated: 2024/03/30 00:10:55 by ialdidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/libft/libft.h"

typedef struct s_item
{
	int		data;
	int		index;
}	t_item;

typedef struct s_stack
{
	t_list	*list;
	int		length;
}	t_stack;

typedef struct s_object
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		max;
}	t_object;

/*		Sort			*/
int		initial_or_second_part(t_list *lst, int target, int size);
int		is_sorted(t_list *lst);
void	sort_three(t_object *obj);
void	sort_five(t_object *obj);
void	sort(t_object *obj);

/*		Parsing			*/
int	stack_init(t_object *obj, char **strs);

/*		List Utilities	*/
int		ft_lstappenditem(t_list **lst, void *content);
int		ft_lstshift_down(t_list **lst);

/*		Instructions	*/
void	push(t_list **stack_from, t_list **stack_to, char *instruction);
void	swap(t_list **stack_a, t_list **stack_b);
void	rotate(t_list **stack_a, t_list **stack_b);
void	reverse_rotate(t_list **stack_a, t_list **stack_b);

/*		Utilities		*/
void	exiter(void);
void	free_array(char **strs);

/*		To be removed	*/
void	print_stacks(t_object obj);

#endif
