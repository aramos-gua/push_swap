#include <stdio.h>

unsigned long long factorial(int n)
{
	if (n < 0)
		return (0);
	if (n == 0 || 1== n)
		return (1);
	else
		return (n * factorial(n - 1));
}

unsigned long long	ft_atoi(char *str)
{
	unsigned long long	number;

	number = 0;
	while (*str)
	{
		number = (number * 10) + (*str - '0');
		str++;
	}
	return (number);
}

int	main(int argc, char **argv)
{
	unsigned long long	number;
	unsigned long long result;

	if (argc == 2)
	{
		(void)argc;
		number = ft_atoi(argv[1]);
		result = factorial(number);
		printf("%llu", result);
	}
	printf("\n");
	return (0);
}
