/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alejandro Ramos <alejandro.ramos.gua@gmai  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:54:34 by Alejandro Ram     #+#    #+#             */
/*   Updated: 2025/03/26 12:39:30 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*last_node(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next != NULL)
	{
		lst = lst -> next;
	}
	return (lst);
}

t_stack	*get_biggest(t_stack *a, int n)
{
	int		biggest;
	t_stack	*max_node;

	if (a == NULL)
		return (NULL);
	biggest = a->number;
	max_node = a;
	while (n)
	{
		if (a->number > biggest)
		{
			biggest = a->number;
			max_node = a;
		}
		a = a->next;
		n--;
	}
	return (max_node);
}

int	ft_lstlen(t_stack *lst)
{
	int		size;

	size = 0;
	while (lst != NULL)
	{
		size++;
		lst = lst -> next;
	}
	return (size);
}
