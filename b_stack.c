/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_stack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alejandro Ramos <alejandro.ramos.gua@gmai  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:45:28 by Alejandro Ram     #+#    #+#             */
/*   Updated: 2025/04/01 11:16:07 by Alejandro Ram    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexation(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = ft_lstlen(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

static void	get_targets_b(t_stack *a, t_stack *b)
{
	t_stack	*target;
	t_stack	*now_a;
	long	best_opt;

	while (b)
	{
		best_opt = LONG_MAX;
		now_a = a;
		while (now_a)
		{
			if ((now_a->number > b->number) && now_a->number < best_opt)
			{
				best_opt = now_a->number;
				target = now_a;
			}
			now_a = now_a->next;
		}
		if (best_opt == LONG_MAX)
			b->target = get_smallest(a, ft_lstlen(a));
		else
			b->target = target;
		b = b->next;
	}
}

void	prepare_b_nodes(t_stack *a, t_stack *b)
{
	indexation(a);
	indexation(b);
	get_targets_b(a, b);
	ft_printf("index head a: %d\n", a->index);
	ft_printf("index head b: %d\n", b->index);
	ft_printf("target node b: %d\n", (b->target)->number);
}
