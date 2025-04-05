/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos <alejandro.ramos.gua@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:10:18 by aramos            #+#    #+#             */
/*   Updated: 2025/03/14 13:52:02 by Alejandro Ram    ###   ########.fr       */
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

static void	free_array(char **array, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(array[i++]);
	free(array);
}

static char	*fill_words(char *str, char c, int *start_w)
{
	int			len_word;
	char		*word;
	int			i;

	i = 0;
	len_word = 0;
	while (str[*start_w] && str[*start_w] == c)
		(*start_w)++;
	while (str[*start_w + len_word] && str[*start_w + len_word] != c)
		++len_word;
	word = malloc((len_word + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (str[*start_w] && str[*start_w] != c)
		word[i++] = str[(*start_w)++];
	word[i] = '\0';
	return (word);
}

char	**split_argv(char *str, char c, int *argc, int *flag)
{
	int		i;
	int		words;
	int		start_w;
	char	**array;

	i = 0;
	start_w = 0;
	words = word_count(str, c);
	array = malloc((words + 2) * sizeof(char *));
	if (!array)
		return (NULL);
	array[i] = malloc(1 * sizeof(char));
	if (!array[i])
		return (free(array), NULL);
	array[i][0] = '\0';
	i++;
	while (words-- > 0)
	{
		array[i] = fill_words(str, c, &start_w);
		if (!array[i])
			return (free_array(array, i), NULL);
		i++;
	}
	*flag = 1;
	*argc = i;
	array[i] = NULL;
	return (array);
}
