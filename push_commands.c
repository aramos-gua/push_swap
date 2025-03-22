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

void	pb(t_astk **a, t_astk **b)
{
	t_astk	*temp;

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
