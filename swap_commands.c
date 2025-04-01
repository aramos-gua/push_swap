/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos <alejandro.ramos.gua@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 13:03:04 by aramos            #+#    #+#             */
/*   Updated: 2025/04/01 13:07:46 by Alejandro Ram    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack, char flag)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;
	int		len_stack;

	len_stack = ft_lstlen(*stack);
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
	first->next = third;
	*stack = second;
	if (flag == 'a')
		ft_printf("sa\n");
	else if (flag == 'b')
		ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a, 's');
	swap(b, 's');
	ft_printf("ss\n");
}
