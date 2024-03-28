void	rotate_and_push(t_object *obj,
	void (*rotate_func)(t_list **, t_list **),
		void (*rotate_func2)(t_list **, t_list **), int *target, int *size)
{
	int	n;

	n = 0;
	while (obj->stack_b)
	{
		rotate_func(NULL, &obj->stack_b);
		if (obj->stack_b->index == *target)
		{
			push(&obj->stack_b, &obj->stack_a, "pa");
			(*size)--;
			*target -= 1;
			break ;
		}
		n++;
	}
	while (n--)
	{
		rotate_func2(NULL, &obj->stack_b);
		if (obj->stack_b->index == *target)
		{
			push(&obj->stack_b, &obj->stack_a, "pa");
			(*size)--;
			*target -= 1;
		}
	}
}
