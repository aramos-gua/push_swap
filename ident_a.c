void	position(t_stack *a, int len)
{
	int	i;
	int	median;

	i = 0;
	if (!a)
		return ;
	median = len / 2;
	while (a)
	{
		stack->position = i;
		if (i <= median)
			a->more_median = true;
		else
			a->more_median = false;
		a = a->next;
		i++:
	}
}
