/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos <alejandro.ramos.gua@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 20:27:37 by aramos            #+#    #+#             */
/*   Updated: 2025/03/22 21:11:29 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (*a == NULL)
		return ;
	temp = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->previous = NULL;
	temp->next = *b;
	if (*b)
		(*b)->previous = temp;
	*b = temp;
	ft_printf("pa\n");
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (*b == NULL)
		return ;
	temp = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->previous = NULL;
	temp->next = *a;
	if (*a)
		(*a)->previous = temp;
	*a = temp;
	ft_printf("pb\n");
}
