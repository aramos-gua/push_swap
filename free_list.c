/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Alejandro Ramos <alejandro.ramos.gua@gmai  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:46:56 by Alejandro Ram     #+#    #+#             */
/*   Updated: 2025/03/11 19:51:27 by Alejandro Ram    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_stack **a, char **argv, int flag, int argc)
{
	int		i;
	t_stack	*temp;

	i = argc;
	if (flag == 1)
	{
		i -= 1;
		while (i >= 0)
			free(argv[i--]);
		free(argv);
	}
	i = 1;
	while (*a)
	{
		temp = (*a)->next;
		free (*a);
		*a = temp;
	}
	write(2, "Error\n", 6);
}

void	free_end(t_stack **a, char **argv, int flag, int argc)
{
	int		i;
	t_stack	*temp;

	i = argc;
	if (flag == 1)
	{
		i -= 1;
		while (i >= 0)
			free(argv[i--]);
		free(argv);
	}
	i = 1;
	while (*a)
	{
		temp = (*a)->next;
		free (*a);
		*a = temp;
	}
}
