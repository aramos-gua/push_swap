/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ident_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alejandro Ramos <alejandro.ramos.gua@gmai  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:40:26 by Alejandro Ram     #+#    #+#             */
/*   Updated: 2025/04/07 08:45:49 by Alejandro Ram    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_targets_a(t_stack *a, t_stack *b)
{
	t_stack	*target;
	t_stack	*now_b;
	long	best_opt;

	while (a)
	{
		best_opt = LONG_MIN;
		now_b = b;
		while (now_b)
		{
			if (now_b->number < a->number && now_b->number > best_opt)
			{
				best_opt = now_b->number;
				target = now_b;
			}
			now_b = now_b->next;
		}
		if (best_opt == LONG_MIN)
			a->target = get_biggest(b, ft_lstlen(b));
		else
			a->target = target;
		a = a->next;
	}
}

static void	get_cost_a(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = ft_lstlen(a);
	len_b = ft_lstlen(b);
	while (a)
	{
		a->moves = a->index;
		if (!(a->above_median))
			a->moves = len_a - (a->index);
		if (a->target->above_median)
			a->moves += a->target->index;
		else
			a->moves += len_b - (a->target->index);
		a = a->next;
	}
}

void	set_fastest(t_stack *stack)
{
	long	least_moves;
	t_stack	*fastest;

	if (!stack)
		return ;
	least_moves = LONG_MAX;
	while (stack)
	{
		if (stack->moves < least_moves)
		{
			least_moves = stack->moves;
			fastest = stack;
		}
		stack = stack->next;
	}
	fastest->fastest = true;
}

t_stack	*get_fastest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->fastest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*fastest;

	fastest = get_fastest(*a);
	ft_printf("fastest is: %d\n", fastest->number);//It works up until here. blocking printf of pb prints this
	if (fastest->above_median && fastest->target->above_median)
		both_rs(a, b, fastest, 2);
	else if (!(fastest->above_median && fastest->target->above_median))
		both_rs(a, b, fastest, 3);
	set_receiver(a, fastest, 'a');
	set_receiver(a, fastest->target, 'b');
	push(b, a, 'b');
}

void	prepare_a_nodes(t_stack *a, t_stack *b)
{
	indexation(a);
	indexation(b);
	get_targets_a(a, b);
	get_cost_a(a, b);
	set_fastest(a);
}
