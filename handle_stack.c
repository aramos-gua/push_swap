/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alejandro Ramos <alejandro.ramos.gua@gmai  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:10:15 by Alejandro Ram     #+#    #+#             */
/*   Updated: 2025/03/16 13:02:35 by aramos           ###   ########.fr       */
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
	t_astk	*temp;

	if (!(*a))
		return ;
	ft_printf("starting sort_abc\n");
	max_node = get_biggest(*a);
	if (*a == max_node)
	{
		ft_printf("starting ra\n");
		ra(a, argc);
	}
	else if ((*a)->next == max_node)
	{
		ft_printf("starting rra\n");
		rra(a, argc);
	}
	if ((*a)->number > ((*a)->next)->number)
		sa(a, argc);
	temp = *a;
	while (temp)
	{
		ft_printf(" %d ->", temp->number);
		temp = temp->next;
	}
}
