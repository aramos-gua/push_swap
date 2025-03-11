/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos <alejandro.ramos.gua@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:10:30 by aramos            #+#    #+#             */
/*   Updated: 2025/03/11 19:26:14 by Alejandro Ram    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

static t_astk	*last_node(t_astk *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next != NULL)
	{
		lst = lst -> next;
	}
	return (lst);
}

static int	isnt_number(char *str)
{
	if (!(*str == '-' || ft_isdigit(*str)))
		return (1);
	while (*(++str))
	{
		if (!(ft_isdigit(*str)))
			return (1);
	}
	return (0);
}

static int	is_repeated(int	number, t_astk *a)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (number == a->number)
			return (1);
		a = a->next;
	}
	return (0);
}

static void new_number(t_astk **a, int number)
{
	t_astk	*box;
	t_astk	*last_one;
	
	if (a == NULL)
		return ;
	box = malloc(sizeof(t_astk));
	if (!box)
		return ;
	box->next = NULL;
	box->number = number;
	if (a == NULL)
		*a = box;
	else
	{
		last_one = last_node(*a);
		last_one->next = box;
		box->previous = last_one;
		last_one->previous = box;
	}
}

static void	validate_input(char **argv, t_astk **a)
{
	int		i;
	long	number;

	i = 1;
	while (argv[i])
	{
		if (isnt_number(argv[i]))
			ft_printf("Error\n");
		number = atoln((const char *)argv[i]);
		if (number > INT_MAX || number < INT_MIN)
			ft_printf("Error\n");
		if (is_repeated(number, *a))
			ft_printf("Error\n");
		new_number(a, number);
		i++;
	}
	return ;
}

int	main(int argc, char **argv)
{
	t_astk	*a;
	t_astk	*b;

	a = NULL;
	b = NULL;
	if (argc < 2 || (argc == 2 && argv[1][0] == '\0'))
		ft_printf("Error\n");
	else if (argc == 2)
		argv = split_argv(argv[1], ' ');
	validate_input(argv, &a);
	return (0);
}
