/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alejandro Ramos <alejandro.ramos.gua@gmai  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:10:15 by Alejandro Ram     #+#    #+#             */
/*   Updated: 2025/03/22 21:15:00 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_astk *a)
{
	t_astk	*temp;

	temp = a;
	if (a == NULL)
		return (1);
	while (temp && temp->next)
	{
		if (temp->number > (temp-> next)->number)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	sort_abc(t_astk **a, int argc)
{
	t_astk	*max_node;

	if (!(*a) || argc != 4)
		return ;
	max_node = get_biggest(*a);
	if (*a == max_node)
		ra(a, argc);
	else if ((*a)->next == max_node)
		rra(a, argc);
	if ((*a)->number > ((*a)->next)->number)
		sa(a, argc);
}

void	sort_five(t_astk **a, t_astk** b, int argc)
{
	ft_printf("Starting sort_five\n");
	pb(a, b);
	pb(a, b);
	argc -= 2;
	sort_abc(a, argc);
}
