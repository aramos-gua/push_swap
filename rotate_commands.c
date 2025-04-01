/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos <alejandro.ramos.gua@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 10:38:05 by aramos            #+#    #+#             */
/*   Updated: 2025/03/16 12:58:10 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static void	rotate(t_stack **stack, char flag)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	last = last_node(*stack);
	first->next = NULL;
	first->previous = last;
	last->next = first;
	second->previous = NULL;
	*stack = second;
	if(flag == 'a')
		ft_printf("ra\n");
	else if(flag == 'b')
		ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a, 'r');
	rotate(b, 'r');
	ft_printf("rr\n");
}

void	rra(t_stack **a, int argc)
{
	t_stack	*last_one;
	t_stack	*second_last;

	if (a == NULL || *a == NULL || (*a)->next == NULL || argc == 2)
		return ;
	last_one = last_node(*a);
	second_last = last_one->previous;
	if (second_last)
		second_last->next = NULL;
	last_one->next = *a;
	last_one->previous = NULL;
	(*a)->previous = last_one;
	*a = last_one;
	ft_printf("rra\n");
}

void	rrb(t_stack **b, int argc)
{
	t_stack	*last_one;
	t_stack	*second_last;

	if (b == NULL || *b == NULL || (*b)->next == NULL || argc == 2)
		return ;
	last_one = last_node(*b);
	second_last = last_one->previous;
	if (second_last)
		second_last->next = NULL;
	last_one->next = *b;
	last_one->previous = NULL;
	(*b)->previous = last_one;
	*b = last_one;
	ft_printf("rrb\n");
}
