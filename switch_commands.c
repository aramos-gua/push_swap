/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos <alejandro.ramos.gua@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 13:03:04 by aramos            #+#    #+#             */
/*   Updated: 2025/03/16 13:04:37 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a, int argc)
{
	t_stack	*temp;

	if (!a || !(*a) || argc < 3)
		return ;
	temp = *a;
	*a = (*a)->next;
	(*a)->previous = NULL;
	temp->next = (*a)->next;
	if (temp->next)
	{
		(temp->next)->previous = temp;
	}
	(*a)->next = temp;
	temp->previous = *a;
	ft_printf("sa\n");
}

void	sb(t_stack **b, int argc)
{
	t_stack	*temp;

	if (!b || !(*b) || argc < 3)
		return ;
	temp = *b;
	*b = (*b)->next;
	(*b)->previous = NULL;
	temp->next = (*b)->next;
	if (temp->next)
	{
		(temp->next)->previous = temp;
	}
	(*b)->next = temp;
	temp->previous = *b;
	ft_printf("sb\n");
}
