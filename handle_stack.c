/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alejandro Ramos <alejandro.ramos.gua@gmai  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:10:15 by Alejandro Ram     #+#    #+#             */
/*   Updated: 2025/04/01 13:09:05 by Alejandro Ram    ###   ########.fr       */
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

void	sort_abc(t_stack **a, int a_len)
{
	t_stack	*max_node;

	if (!(*a) || a_len != 3)
		return ;
	max_node = get_biggest(*a, a_len);
	if (*a == max_node)
		rotate(a, 'a');
	else if ((*a)->next == max_node)
		reverse_rotate(a, 'a');
	if ((*a)->number > ((*a)->next)->number)
		swap(a, 'a');
}

void	sort_all(t_stack **a, t_stack ** b)
{
	int	a_len;

	a_len = ft_lstlen(*a);
	if (a_len-- > 3 && !(is_sorted(*a)))
		push(a, b, 'b');
	sort_abc(a, a_len);
	while (*b)
	{
		prepare_b_nodes(*a, *b);
		*b = (*b)->next;
	}
}

//void	sort_abcd(t_stack **a, int argc)
//{
//	int	e;
//	int	b;
//	int	c;
//	int	d;
//
//	e = (*a)->number;
//	b = ((*a)->next)->number;
//	c = (((*a)->next)->next)->number;
//	d = ((((*a)->next)->next)->next)->number;
//	if (argc == 5)
//	{
//	//	if (!(is_sorted(*a) && e == 2 && b == 3 && c == 1 && d == 4))
//	//		rra(a, argc), rra(a, argc), sa(a, argc), ra(a, argc);
//		if (!(is_sorted(*a)) && e < b && c < d && get_biggest(*a, 4)->number != e)
//			ra(a, argc), sa(a, argc), ra(a, argc);
//		if (!(is_sorted(*a)) && e < b && c < d && get_biggest(*a, 4)->number != d)
//			sa(a, argc), ra(a, argc), sa(a, argc);		
//		if (!(is_sorted(*a)) && e > b)
//			sa(a, argc);
//		if (!(is_sorted(*a)) && b > c)
//		{
//			if (c > d)
//				rra(a, argc), rra(a, argc), sa(a, argc);
//			else
//				ra(a, argc), ra(a, argc);
//		}
//	}
//}
