/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alejandro Ramos <alejandro.ramos.gua@gmai  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:10:15 by Alejandro Ram     #+#    #+#             */
/*   Updated: 2025/04/07 08:45:29 by Alejandro Ram    ###   ########.fr       */
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

void	sort_abc(t_stack **a)
{
	t_stack	*max_node;
	int		a_len;

	a_len = ft_lstlen(*a);
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

int	has_chunk_elements(t_stack *stack, int min, int max)
{
	while (stack)
	{
		if (stack->number >= min && stack->number <=max)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	find_closest_chunk_element(t_stack *stack, int min, int max)
{
	int	pos = 0;
	int closest_pos = -1;
	int stack_size = ft_lstlen(stack);
	int	min_distance = stack_size;

	while (stack)
	{
		if (stack->number >= min && stack->number <= max)
		{
			int	distance = pos;
			if (pos > (stack_size / 2))
				distance = stack_size - pos;
			if (distance < min_distance)
			{
				min_distance = distance;
				closest_pos = pos;
			}
		}
		stack = stack->next;
		pos++;
	}
	return (closest_pos);
}

void	rotate_to_position(t_stack **stack, int pos, char flag)
{
	int	stack_size = ft_lstlen(*stack);

	if (pos <= (stack_size / 2))
	{
		while (pos-- > 0)
			rotate(stack, flag);
	}
	else
	{
		pos = stack_size - pos;
		while (pos-- > 0)
			reverse_rotate(stack, flag);
	}
}

void	sort_all(t_stack **a, t_stack **b)
{
	t_stack	*max_node;
	t_stack	*min_node;
	int		chunk_size;
	int		chunk_count;
	int		min_val;
	int		max_val;
	int		a_len;
	int		i;

	i = 0;
	chunk_count = 5;
	a_len = ft_lstlen(*a);
	max_node = get_biggest(*a, a_len);
	min_node = get_smallest(*a, a_len);
	max_val = max_node->number;
	min_val = min_node->number;
	chunk_size = (max_val - min_val)/ chunk_count + 1;
	while (i < chunk_count)
	{
		int	chunk_min = min_val + (i *chunk_size);
		int	chunk_max = chunk_min + chunk_size - 1;
		while (has_chunk_elements(*a, chunk_min, chunk_max) && a_len > 3)
		{
			//t_stack	*current = *a;
			int	closest_pos = find_closest_chunk_element(*a, chunk_min, chunk_max);

			rotate_to_position(a, closest_pos, 'a');
			push(a, b, 'b');
			a_len--;
		}
		i++;
	}
	sort_abc(a);
	while (*b)
	{
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
