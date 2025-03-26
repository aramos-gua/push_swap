/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos <alejandro.ramos.gua@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:10:25 by aramos            #+#    #+#             */
/*   Updated: 2025/03/26 12:39:40 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_stack
{
	int				number;
	int				moves;
	struct s_stack	*previous;
	struct s_stack	*next;
}	t_stack;

char	**split_argv(char *str, char c, int *argc, int *flag);
long	atoln(const char *str);
t_stack	*last_node(t_stack *lst);
void	free_all(t_stack **a, char **argv, int flag, int argc);
void	new_number(t_stack **stack, int number);
int		is_sorted(t_stack *a);
void	sort_abc(t_stack **a, int argc);
t_stack	*get_biggest(t_stack *a);
void	ra(t_stack **a, int argc);
void	sa(t_stack **a, int argc);
void	rra(t_stack **a, int argc);
void	sort_five(t_stack **a, t_stack** b, int argc);
void	pb(t_stack **a, t_stack **b);
int		get_median(t_stack *a, int size);
