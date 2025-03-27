/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ident_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alejandro Ramos <alejandro.ramos.gua@gmai  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:40:26 by Alejandro Ram     #+#    #+#             */
/*   Updated: 2025/03/27 16:52:35 by Alejandro Ram    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	position(t_stack *a, int len)
{
	int	i;
	int	median;

	i = 0;
	if (!a)
		return ;
	median = len / 2;
	ft_printf("the median is: %d\n", median);
	while (a)
	{
		a->position = i;
		if (i <= median)
			a->above_median = true;
		else
			a->above_median = false;
		ft_printf("a number: %d\n", a->number);
		ft_printf("a position in stack: %d\n", a->position);
		ft_printf("a is above median?: %d\n\n", a->above_median);
		a = a->next;
		i++;
	}
}

void	set_target(t_stack *a, t_stack *b)
{
	t_stack	*current_b;
	t_stack	*target;
	long	target_index;

	while (a)
	{
		target_index = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->number < a->number
				&& current_b->number > target_index)
			{
				target_index = current_b->number;
				target = current_b;
			}
			current_b = current_b->next;
		}
		ft_printf("target_index value %li\n", target_index);
		if (target_index == LONG_MIN)
			a->target = get_biggest(b);
		else
			a->target = target;
		ft_printf("\na->target: %d\n", a->target);
		a = a->next;
	}
}
