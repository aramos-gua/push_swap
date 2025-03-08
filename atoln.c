/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoln.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos <alejandro.ramos.gua@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:13:55 by aramos            #+#    #+#             */
/*   Updated: 2025/03/08 19:17:44 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	long		num;
	int			sign;

	sign = 1;
	num = 0;
	while ((*str > 8 && *str < 14) || *str == ' ')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		if (*(str + 1) >= '0' && *(str + 1) <= '9')
		{
			str++;
			break ;
		}
		return (0);
	}
	while (*str >= '0' && *str <= '9')
		num = num * 10 + (*str++ - '0');
	return (num * sign);
}

