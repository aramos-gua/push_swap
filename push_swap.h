/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos <alejandro.ramos.gua@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:10:25 by aramos            #+#    #+#             */
/*   Updated: 2025/03/16 10:43:46 by aramos           ###   ########.fr       */
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
int		is_sorted(t_astk *a);
void	sort_abc(t_astk **a, int argc);
t_astk	*get_biggest(t_astk *a);
void	ra(t_astk **a, int argc);
