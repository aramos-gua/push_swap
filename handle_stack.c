/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alejandro Ramos <alejandro.ramos.gua@gmai  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:10:15 by Alejandro Ram     #+#    #+#             */
/*   Updated: 2025/03/26 12:39:53 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	t_stack	*temp;

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

void	sort_abc(t_stack **a, int argc)
{
	t_stack	*max_node;

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

void	ident_a(t_stack *a, t_stack *b, int argc)
{
	position(a);
	position(b);
	set_target(a, b);
	check_price(a, b);
	set_price(a);
}

void	sort_algo(t_stack **a, t_stack **b, int argc)
{
	int	len;

	len = argc - 1;
	if (len-- > 3 && !(is_sorted(*a)))
		pb(a, b);
	if (len-- > 3 && !(is_sorted(*a)))
		pb(a, b);
	while (len > 3 && (is_sorted(*a)))
	{
		ident_a(*a, *b, len);
		atob(*a, *b);
		len--;
	}
	sort_abc(a, len + 1);
	while (*b)
	{
		ident_b(*a, *b);
		btoa(*a, *b);
	}
	index(*a);

}
