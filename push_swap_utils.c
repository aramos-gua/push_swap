/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alejandro Ramos <alejandro.ramos.gua@gmai  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:54:34 by Alejandro Ram     #+#    #+#             */
/*   Updated: 2025/04/01 11:13:31 by Alejandro Ram    ###   ########.fr       */
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

t_stack	*get_biggest(t_stack *lst, int n)
{
	int		biggest;
	t_stack	*max_node;

	if (lst == NULL)
		return (NULL);
	biggest = lst->number;
	max_node = lst;
	while (n)
	{
		if (lst->number > biggest)
		{
			biggest = lst->number;
			max_node = lst;
		}
		lst = lst->next;
		n--;
	}
	return (max_node);
}

t_stack	*get_smallest(t_stack *lst, int n)
{
	int		smallest;
	t_stack	*min_node;

	if (lst == NULL)
		return (NULL);
	smallest = lst->number;
	min_node = lst;
	while (n)
	{
		if (lst->number < smallest)
		{
			smallest = lst->number;
			min_node = lst;
		}
		lst = lst->next;
		n--;
	}
	return (min_node);
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
