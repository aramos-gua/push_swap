/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos <alejandro.ramos.gua@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:10:30 by aramos            #+#    #+#             */
/*   Updated: 2025/03/08 19:15:40 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

int	no_number(char *str)
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



void	validate_input(char **argv)
{
	int		i;
	long	number;

	i = 1;
	while (argv[i])
	{
		if (no_number(argv[i]))
			ft_printf("Error");
		number = atoln((const char *)argv[i]);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char	*invalid;
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	invalid = "Error";
	if (argc < 2 || (argc == 2 && argv[1][0] == '\0'))
		ft_printf("%s\n", invalid);
	else if (argc == 2)
		argv = split_argv(argv[1], ' ');
	validate_input(argv);
}
