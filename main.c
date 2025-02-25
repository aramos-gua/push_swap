#include <stdio.h>
#define MAX_DIGITS 10000

int	multiply(int result[], int result_size, int multiplier)
{
	int	carry;
	int	i;

	i = 0;
	carry = 0;
	while (i < result_size)
	{
		int prod = result[i] * multiplier + carry;
		result[i] = prod % 10;
		carry = prod / 10;
		i++;
	}
	while (carry)
	{
		result[result_size] = carry % 10;
		carry /= 10;
		result_size++;
	}
	return (result_size);
}

void	factorial(int n)
{
	int	result[MAX_DIGITS];
	int	result_size;
	int	i;

	i = 2;
	result[0] = 1;
	result_size = 1;
	while (i <= n)
	{
		result_size = multiply(result, result_size, i);
		i++;
	}
	i = result_size - 1;
	while (i >= 0)
	{
		printf("%d", result[i]);
		i--;
	}
}

int	ft_atoi(char *str)
{
	int	number;

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
	int	number;

	if (argc != 2)
		return (1);
	number = ft_atoi(argv[1]);
	factorial(number);
	printf("\n");
	return (0);
}
