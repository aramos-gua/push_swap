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
	ft_printf("starting sort_abc\n");
	max_node = get_biggest(*a);
	if (*a == max_node)
		ra(a, argc);
	if ((*a)->number > ((*a)->next)->number)
		sa(a, argc);
	ft_printf("number[1]: %d\n", (*a)->number);
	*a = (*a)->next;
	ft_printf("number[2]: %d\n", (*a)->number);
	*a = (*a)->next;
	ft_printf("number[3]: %d\n", (*a)->number);
}
