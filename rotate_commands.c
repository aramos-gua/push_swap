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

void	ra(t_stack **a, int argc)
{
	t_stack	*last_one;
	t_stack	*temp;

	if (a == NULL || *a == NULL || argc == 2)
		return ;
	last_one = last_node(*a);
	temp = *a;
	*a = (*a)->next;
	(*a)->previous = NULL;
	last_one->next = temp;
	temp->previous = last_one;
	temp->next = NULL;
	ft_printf("ra\n");
}

void	rb(t_stack **b, int argc)
{
	t_stack	*last_one;
	t_stack	*temp;

	if (b == NULL || *b == NULL || argc == 2)
		return ;
	last_one = last_node(*b);
	temp = *b;
	*b = (*b)->next;
	(*b)->previous = NULL;
	last_one->next = temp;
	temp->previous = last_one;
	temp->next = NULL;
	ft_printf("rb\n");
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
