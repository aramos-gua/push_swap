/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos <alejandro.ramos.gua@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:10:25 by aramos            #+#    #+#             */
/*   Updated: 2025/03/27 15:45:06 by Alejandro Ram    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct s_stack
{
	int				number;
	int				position;
	int				moves;
	bool			above_median;
	bool			fastest;
	struct s_stack	*target;
	struct s_stack	*previous;
	struct s_stack	*next;
}	t_stack;

// Handle Iput
char	**split_argv(char *str, char c, int *argc, int *flag);
long	atoln(const char *str);
void	new_number(t_stack **stack, int number);

// Commands
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

void	ra(t_stack **a);
void	rra(t_stack **a);

// Traverse the linked list
t_stack	*last_node(t_stack *lst);
void	free_all(t_stack **a, char **argv, int flag, int argc);
int		ft_lstlen(t_stack *lst);
void	position(t_stack *a, int len);

// Traverse stack
int		is_sorted(t_stack *a);
t_stack	*get_biggest(t_stack *a, int n);
void	set_target(t_stack *a, t_stack *b);
int		get_median(t_stack *a, int size);

// Sort
void	sort_abc(t_stack **a, int argc);
void	sort_algo(t_stack **a, t_stack **b, int argc);
void	sort_abcd(t_stack **a, int argc);
