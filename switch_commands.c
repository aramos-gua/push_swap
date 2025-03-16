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

void	sa(t_astk **a, int argc)
{
	t_astk	*temp;

	if (!a || !(*a) || argc < 3)
	temp = *a;
	*a = (*a)->next;
	(*a)->previous = NULL;
	temp->next = (*a)->next;
	if (temp->next)
		(temp->next)->previous = temp;
	(*a)->next = temp;
	temp->previous = *a;
}
