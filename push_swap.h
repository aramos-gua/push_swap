/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos <alejandro.ramos.gua@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:10:25 by aramos            #+#    #+#             */
/*   Updated: 2025/04/01 14:07:07 by Alejandro Ram    ###   ########.fr       */
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
	int				index;
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
void	swap(t_stack **stack, char flag);
void	ss(t_stack **a, t_stack **b);
void	push(t_stack **source, t_stack **dest, char flag);
void	rotate(t_stack **stack, char flag);
void	rr(t_stack **a, t_stack **b);
void	reverse_rotate(t_stack **stack, char flag);
void	rrr(t_stack **a, t_stack **b);

// Traverse the linked list
t_stack	*last_node(t_stack *lst);
void	free_all(t_stack **a, char **argv, int flag, int argc);
int		ft_lstlen(t_stack *lst);
void	position(t_stack *a, int len);

// Prepare nodes
void	back_to_a(t_stack **a, t_stack **b);
void	set_receiver(t_stack **stack, t_stack *target, char flag);

// Traverse stacks
int		is_sorted(t_stack *a);
t_stack	*get_biggest(t_stack *a, int n);
t_stack	*get_smallest(t_stack *lst, int n);
void	prepare_b_nodes(t_stack *a, t_stack *b);
void	indexation(t_stack *stack);
//void	set_target(t_stack *a, t_stack *b);
//int		get_median(t_stack *a, int size);

// Sort
void	sort_abc(t_stack **a, int argc);
void	sort_all(t_stack **a, t_stack ** b);
