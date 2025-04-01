/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos <alejandro.ramos.gua@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 13:03:04 by aramos            #+#    #+#             */
/*   Updated: 2025/03/27 15:43:15 by Alejandro Ram    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **stack, int len_stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (!stack || !(*stack) || len_stack < 2)
		return ;
	first = *stack;
	second = first->next;
	third = second->next;
	second->previous = NULL;
	first->next = third;
	if (third)
		third->previous = first;
	second->next = first;
	first->next = second;
	*stack = second;
}

void	sa(t_stack **a)
{
	int	len_stack;

	len_stack = ft_lstlen(*a);
	swap(a, len_stack);
	ft_printf("sa\n");
}

void	sb(t_stack **b)
{
	int	len_stack;
	
	len_stack = ft_lstlen(*b);
	swap(b, len_stack);
	ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a, ft_lstlen(*a));
	swap(b, ft_lstlen(*b));
	ft_printf("ss\n");
}
