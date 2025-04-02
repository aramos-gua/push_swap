/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alejandro Ramos <alejandro.ramos.gua@gmai  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:10:15 by Alejandro Ram     #+#    #+#             */
/*   Updated: 2025/04/01 14:16:24 by Alejandro Ram    ###   ########.fr       */
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
	{
	//	ft_printf("Pushing first time\n");
		push(a, b, 'b');
	}
	while (a_len-- > 3 && !(is_sorted(*a)))
	{
	//	ft_printf("Pushing one more time\n");
		push(a, b, 'b');
	}
	//ft_printf("Calling sort_abc, len of a: %d\n", a_len);
	sort_abc(a, a_len + 1);
	//t_stack	*temp = *a;
	//while (temp)
	//{
	//	ft_printf(" %d -> ", (*temp).number);
	//	temp = temp->next;
	//}
	//ft_printf("done with sort_abc\n");
	while (*b)
	{
		//ft_printf("preparing b nodes\n");
		prepare_b_nodes(*a, *b);
		back_to_a(a, b);
	}
	indexation(*a);
	set_receiver(a, get_smallest(*a, ft_lstlen(*a)), 'a');
}

void	set_receiver(t_stack **stack, t_stack *target, char flag)
{
	while (*stack != target)
	{
		if (flag == 'a')
		{
			if (target->above_median)
				rotate(stack, 'a');
			else if (!(target->above_median))
					reverse_rotate(stack, 'a');
		}
		else if (flag == 'b')
		{
			if (target->above_median)
				rotate(stack, 'b');
			else if (!(target->above_median))
					reverse_rotate(stack, 'b');

		}
	}
}
