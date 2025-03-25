/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alejandro Ramos <alejandro.ramos.gua@gmai  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:54:34 by Alejandro Ram     #+#    #+#             */
/*   Updated: 2025/03/11 19:38:01 by Alejandro Ram    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_astk	*last_node(t_astk *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next != NULL)
	{
		lst = lst -> next;
	}
	return (lst);
}

t_astk	*get_biggest(t_astk *a)
{
	int		biggest;
	t_astk	*max_node;

	if (a == NULL)
		return (NULL);
	biggest = a->number;
	max_node = a;
	while (a)
	{
		if (a->number > biggest)
		{
			biggest = a->number;
			max_node = a;
		}
		a = a->next;
	}
	return (max_node);
}

t_astk  *find_least(t_astk **a)
{
  
}
