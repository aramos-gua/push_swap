/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos <alejandro.ramos.gua@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:10:30 by aramos            #+#    #+#             */
/*   Updated: 2025/03/26 12:57:13 by aramos           ###   ########.fr       */
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

static int	is_repeated(int number, t_stack *a)
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

void	new_number(t_stack **stack, int number)
{
	t_stack	*box;
	t_stack	*last_one;

	if (stack == NULL)
		return ;
	box = malloc(1 * sizeof(t_stack));
	if (!box)
		return ;
	box->next = NULL;
	box->number = number;
	if (*stack == NULL)
	{
		*stack = box;
		box->previous = NULL;
	}
	else
	{
		last_one = last_node(*stack);
		last_one->next = box;
		box->previous = last_one;
	}
}

static int	validate_input(char **argv, t_stack **a, int flag, int argc)
{
	int		i;
	long	number;

	i = 1;
	while (argv[i])
	{
		if (isnt_number(argv[i]))
			return (free_all(a, argv, flag, argc), 1);
		number = atoln((const char *)argv[i]);
		if (number > INT_MAX || number < INT_MIN)
			return (free_all(a, argv, flag, argc), 1);
		if (is_repeated(number, *a))
			return (free_all(a, argv, flag, argc), 1);
		if (argc == 2)
			return (free_all(a, argv, flag, argc), 1);
		new_number(a, number);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	//t_stack	*b;
	int		flag;
	//int		median;

	a = NULL;
	//b = NULL;
	flag = 0;
	if (argc < 2 || (argc == 2 && !(argv[1][0])))
		return (ft_printf("Error\n"), 1);
	if (argc == 2)
		argv = split_argv(argv[1], ' ', &argc, &flag);
	if (validate_input(argv, &a, flag, argc) == 1)
		return (1);
	if ((is_sorted(a)))
		ft_printf("Sorted!\n");
	if (!(is_sorted(a)))
	{
		ft_printf("Not sorted\n");
		if (argc == 4)
			sort_abc(&a, argc);
		//median = get_median(a, argc - 1);
		sort_algo(a, b, argc);
	}
	return (0);
}
