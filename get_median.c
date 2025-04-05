/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_median.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramos <alejandro.ramos.gua@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:30:33 by aramos            #+#    #+#             */
/*   Updated: 2025/03/26 12:57:04 by aramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int *list_to_array(t_stack *a, int size)
{
    t_stack	*tmp = a;
    int		*arr;
	int		i;

	arr = malloc(size * sizeof(int));
    i = 0;
    while (tmp)
    {
        arr[i++] = tmp->number;
        tmp = tmp->next;
    }
    return (arr);
}

static void insertion_sort(int *arr, int size)
{
    int	i;
	int	j;
	int	key;

	i = 1;
    while (i < size)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
		i++;
    }
}

int get_median(t_stack *a, int size)
{
	int	median;
    int	*arr;

	arr = list_to_array(a, size);
    if (!arr)
        return 0;
    insertion_sort(arr, size);
    median = arr[size / 2];
    free(arr);
    return (median);
}
