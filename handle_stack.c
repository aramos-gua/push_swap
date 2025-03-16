/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alejandro Ramos <alejandro.ramos.gua@gmai  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:10:15 by Alejandro Ram     #+#    #+#             */
/*   Updated: 2025/03/16 10:42:02 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_astk *a)
{
	if (a == NULL)
		return (1);
	while (a->next != NULL)
	{
		if (a->number > (a-> next)->number)
			return (0);
		*a = *a->next;
	}
	return (1);
}

void	sort_abc(t_astk **a, int argc)
{
	t_astk	*max_node;
	if (!(*a))
		return ;
	max_node = get_biggest(*a);
	if (*a == max_node)
	{
		ft_printf("ra\n");
		ra(a, argc);
	}
		
}
