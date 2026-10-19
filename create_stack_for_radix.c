/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_for_radix.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalrofat <aalrofat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:49:04 by aalrofat          #+#    #+#             */
/*   Updated: 2025/12/02 12:49:37 by aalrofat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_array(t_stack *a)
{
	int	len;
	int	*array;

	len = count_stack(a);
	array = (int *)malloc(len * sizeof(int));
	if (array == NULL)
		return ;
	fill_array(a, array);
	sort_array(array, len);
	index_stack(a, array, len);
	free(array);
}

void	fill_array(t_stack *a, int *array)
{
	int	x;

	x = 0;
	while (a != 0)
	{
		array[x] = a->data;
		a = a->next;
		x++;
	}
}

void	sort_array(int *array, int len)
{
	int	temp;
	int	x;
	int	j;

	x = 0;
	while (x < len - 1)
	{
		j = 0;
		while (j < len - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		x++;
	}
}

void	index_stack(t_stack *a, int *array, int len)
{
	t_stack	*temp;
	int		j;

	temp = a;
	while (temp != 0)
	{
		j = 0;
		while (j < len)
		{
			if (temp->data == array[j])
				temp->index = j;
			j++;
		}
		temp = temp->next;
	}
}
