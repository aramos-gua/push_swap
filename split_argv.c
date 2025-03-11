/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos <alejandro.ramos.gua@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:10:18 by aramos            #+#    #+#             */
/*   Updated: 2025/03/11 19:20:20 by Alejandro Ram    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	word_count(char *str, char c)
{
	int	words;
	
	words = 0;
	while (*str && *str == c)
		str++;
	while (*str)
	{
		words++;
		while (*str && *str != c)
			str++;
		while (*str && *str == c)
			str++;
	}
	return (words);
}

static char	*fill_words(char *str, char c)
{
	static int	start_w = 0;
	int			len_word;
	char		*word;
	int			i;

	i = 0;
	len_word = 0;
	while (str[start_w] && str[start_w] == c)
		start_w++;
	while (str[start_w + len_word] && str[start_w + len_word] != c)
		++len_word;
	word = malloc((len_word + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (str[start_w] && str[start_w] != c)
		word[i++] = str[start_w++];
	word[i] = '\0';
	return (word);
}

char	**split_argv(char *str, char c)
{
	int		i;
	int		words;
	char	**array;

	i = 0;
	words = word_count(str, c);
	array = malloc((words + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	while (words-- > 0)
	{
		if (i == 0)
		{
			array[i] = malloc(1 * sizeof(char));
			if (!array[i])
				return (NULL);
			array[i][0] = '\0';
			i++;
		}
		array[i++] = fill_words(str, c);
	}
	array[i] = NULL;
	return (array);
}
