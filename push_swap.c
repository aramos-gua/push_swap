#include "push_swap.h" 

int	validate_input(char *str)
{
	while (*str)
	{
		if (*str == '-')
		{
			if (*(str - 1) != ' ')
				return (1);
			else if (!(ft_isdigit(*(str + 1))))
				return (1);
		}
		else if (!(ft_isdigit(*str) || *str == ' '))
			return (1);
		str++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char	*invalid;

	invalid = "Error";
	if (argc < 2)
		ft_printf("%s\n", invalid);
	else if (argc == 2 && (validate_input(argv[1])))
		ft_printf("%s\n", invalid);
}
