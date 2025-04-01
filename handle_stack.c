/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alejandro Ramos <alejandro.ramos.gua@gmai  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:10:15 by Alejandro Ram     #+#    #+#             */
/*   Updated: 2025/03/27 16:21:51 by Alejandro Ram    ###   ########.fr       */
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
	ft_printf("will get biggest \n");
	max_node = get_biggest(*a, argc - 1);
	ft_printf("biggest:  %d\n", max_node->number);
	if (*a == max_node)
		ra(a, argc);
	else if ((*a)->next == max_node)
		rra(a, argc);
	if ((*a)->number > ((*a)->next)->number)
		sa(a, argc);
}

void	ident_a(t_stack *a, t_stack *b, int argc)
{
	position(a, argc);
	//position(b, argc);
	set_target(a, b);
	//check_price(a, b);
	//set_price(a);
}

void	ident_b(t_stack *a, t_stack *b, int argc)
{
	position(b, argc);
	//position(a, argc);
	set_target(b, a);
	//check_price(b, a);
	//set_price(b);
}

void	sort_algo(t_stack **a, t_stack **b, int argc)
{
	int	len;

	len = argc - 1;
	if (len-- > 3 && !(is_sorted(*a)))
		pb(a, b);
	if (len-- > 3 && !(is_sorted(*a)))
		pb(a, b);
	while (len > 3 && !(is_sorted(*a)))
	{
		ft_printf("Starting sort_algo\n");
		ident_a(*a, *b, len);
		//atob(*a, *b);
		len--;
	}
	sort_abc(a, len + 1);
	while (*b)
	{
		ident_b(*a, *b, ft_lstlen(*b));
		btoa(*a, *b);
	}
	//index(*a);
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
