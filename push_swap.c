/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos <alejandro.ramos.gua@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:10:30 by aramos            #+#    #+#             */
/*   Updated: 2025/03/11 19:51:30 by Alejandro Ram    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

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
	box = malloc(1 * sizeof(t_astk));
	if (!box)
		return ;
	box->next = NULL;
	box->number = number;
	if (*a == NULL)
	{
		*a = box;
		box->previous = NULL;
	}
	else
	{
		last_one = last_node(*a);
		last_one->next = box;
		box->previous = last_one;
	}
	ft_printf("new number: %d\n", box->number);
}

static void	validate_input(char **argv, t_astk **a, int flag, int argc)
{
	int		i;
	long	number;

	i = 1;
	flag = 1;//delete
	argc = 2;//delete
	while (argv[i])
	{
		if (isnt_number(argv[i]))
		{
			free_all(a, argv, flag, argc);
			ft_printf("Error\n");
		}
		number = atoln((const char *)argv[i]);
		if (number > INT_MAX || number < INT_MIN)
		{
			ft_printf("Error\n");
			return ;
		}
		if (is_repeated(number, *a))
		{
			ft_printf("Error\n");
			return ;
		}
		new_number(a, number);
		i++;
	}
	return ;
}

int	main(int argc, char **argv)
{
	t_astk	*a;
	t_astk	*b;
	int		flag;

	a = NULL;
	b = NULL;
	flag = 0;
	if (argc < 2 || (argc == 2 && argv[1][0] == '\0'))
		return (ft_printf("Error\n"), 1);
	if (argc == 2)
		argv = split_argv(argv[1], ' ', &argc, &flag);
	validate_input(argv, &a, flag, argc);
	return (0);
}
