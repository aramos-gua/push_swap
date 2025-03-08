/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos <alejandro.ramos.gua@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:10:30 by aramos            #+#    #+#             */
/*   Updated: 2025/03/07 14:10:31 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

int	validate_input(char **argv)
{
	char	*invalid;
	int	i;

	i = 1;
	invalid = "Error";
	while (argv[i])
	{
		if (argv[i] == '-')
		{
			if (!(ft_isdigit(argv[i + 1]))
				ft_printf("%s", invalid);
		}
		else if (!(ft_isdigit(argv[i])))
			ft_printf("%s", invalid);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char	*invalid;

	invalid = "Error";
	if (argc < 2 || (argc == 2 && argv[1][0] == '\0'))
		ft_printf("%s\n", invalid);
	else if (argc == 2)
		argv = split_argv(argv[1], ' ');
	validate_input(argv);
}
