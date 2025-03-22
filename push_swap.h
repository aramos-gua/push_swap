/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos <alejandro.ramos.gua@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:10:25 by aramos            #+#    #+#             */
/*   Updated: 2025/03/22 21:04:46 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_astk
{
	int				number;
	struct s_astk	*previous;
	struct s_astk	*next;
}	t_astk;

char	**split_argv(char *str, char c, int *argc, int *flag);
long	atoln(const char *str);
t_astk	*last_node(t_astk *lst);
void	free_all(t_astk **a, char **argv, int flag, int argc);
void	new_number(t_astk **stack, int number);
int		is_sorted(t_astk *a);
void	sort_abc(t_astk **a, int argc);
t_astk	*get_biggest(t_astk *a);
void	ra(t_astk **a, int argc);
void	sa(t_astk **a, int argc);
void	rra(t_astk **a, int argc);
void	sort_five(t_astk **a, t_astk** b, int argc);
void	pb(t_astk **a, t_astk **b);
