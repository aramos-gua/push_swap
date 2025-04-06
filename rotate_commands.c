/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos <alejandro.ramos.gua@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 10:38:05 by aramos            #+#    #+#             */
/*   Updated: 2025/04/01 11:52:56 by Alejandro Ram    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack, char flag)
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
	if (flag == 'a')
		ft_printf("ra\n");
	else if (flag == 'b')
		ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a, 'r');
	rotate(b, 'r');
	ft_printf("rr\n");
}

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("%d -> ", stack->number);
		stack = stack->next;
	}
	printf("NULL\n");
}

void	reverse_rotate(t_stack **stack, char flag)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*bef_last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	last = last_node(*stack);
	bef_last = last->previous;
	if (bef_last)
		bef_last->next = NULL;
	last->next = first;
	first->previous = last;
	*stack = last;
	if (flag == 'a')
		ft_printf("rra\n");
	else if (flag == 'b')
		ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a, 'r');
	reverse_rotate(b, 'r');
	ft_printf("rrr\n");
}
