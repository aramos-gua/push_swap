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

void	ra(t_astk **a, int argc)
{
	t_astk	*last_one;
	t_astk	*temp;

	if (a == NULL || *a == NULL || argc == 2)
		return ;
	last_one = last_node(*a);
	temp = *a;
	*a = (*a)->next;
	(*a)->previous = NULL;
	last_one->next = temp;
	temp->previous = last_one;
	temp->next = NULL;
}

void	rra(t_astk **a, int argc)
{
	t_astk	*last_one;
	t_astk	*temp;

	if (a == NULL || *a == NULL || argc == 2)
		return ;
	last_one = last_node(*a);
	temp = *a;
	(*a)->next = ((*a)->previous)->previous;
	(*a)->previous = NULL;
	((*a)-> next)->previous = temp;
	(((*a)->next)->next)->next = NULL;
}
