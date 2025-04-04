/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos <alejandro.ramos.gua@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:10:30 by aramos            #+#    #+#             */
/*   Updated: 2025/04/01 17:18:55 by Alejandro Ram    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

static int	isnt_number(char *str)
{
	if (!(*str == '-' || *str == '+' || ft_isdigit(*str)))
		return (1);
	if ((*str == '-' || *str == '+') && !ft_isdigit(str[1]))
		return(1);
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
	//	ft_printf("number: % d\n", number);
		if (number > INT_MAX || number < INT_MIN)
			return (free_all(a, argv, flag, argc), 1);
		number = (int)number;
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
	t_stack	*b;
	int		flag;

	a = NULL;
	b = NULL;
	flag = 0;
	if (argc == 2 && !(argv[1][1]))
		return (write(2, "Error\n", 6), 1);
	if (argc == 1)
		return (1);
	if (argc == 2)
		argv = split_argv(argv[1], ' ', &argc, &flag);
	if (validate_input(argv, &a, flag, argc) == 1)
		return (1);
//	if (is_sorted(a))
//		ft_printf("IS SORTED!\n");
	if (!(is_sorted(a)))
	{
	//	ft_printf("IS NOT SORTED!\n");
		if (argc == 3)
		{
	//		ft_printf("Starting swap\n");
			swap(&a, 'a');
		}
		if (argc == 4)
		{
	//		ft_printf("Starting sort_abc\n");
			sort_abc(&a, argc - 1);
		}
		else
		{
	//		ft_printf("Starting sort_all\n");
			sort_all(&a, &b);
		}
		if (is_sorted(a))
		{
	//		ft_printf("\nIS NOW SORTED!\n");
			t_stack	*temp = a;
			while (temp)
			{
	//			ft_printf(" %d -> ", temp->number);
				temp = temp->next;
			}
		}
	}
	return (0);
}
