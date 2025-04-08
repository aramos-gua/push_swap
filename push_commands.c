/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos <alejandro.ramos.gua@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 20:27:37 by aramos            #+#    #+#             */
/*   Updated: 2025/04/01 14:03:50 by Alejandro Ram    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **source, t_stack **dest, char flag)
{
	t_stack	*temp;

	if (!(*source))
		return ;
	temp = *source;
	*source = (*source)->next;
	if (*source)
		(*source)->previous = NULL;
	temp->previous = NULL;
	if (*dest)
	{
		temp->next = *dest;
		(*dest)->previous = temp;
		*dest = temp;
	}
	else
	{
		*dest = temp;
		temp->next = NULL;
	}
	if (flag == 'a')
		ft_printf("pa\n");
	else if (flag == 'b')
		ft_printf("pb\n");
}
