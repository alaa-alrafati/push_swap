/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_algorathem.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalrofat <aalrofat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:50:01 by aalrofat          #+#    #+#             */
/*   Updated: 2025/12/02 12:50:34 by aalrofat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	find_the_max_bit(t_stack *a)
{
	int	max_index;
	int	bit;

	max_index = 0;
	while (a != 0)
	{
		if (a->index > max_index)
			max_index = a->index;
		a = a->next;
	}
	bit = 0;
	while ((max_index >> bit) != 0)
		bit++;
	return (bit);
}

void	radix_algorathem(t_stack **a, t_stack **b)
{
	int	max_bit;
	int	count;
	int	circle;

	max_bit = find_the_max_bit(*a);
	circle = 0;
	while (circle < max_bit)
	{
		count = count_stack(*a);
		while (count != 0)
		{
			if ((((*a)->index >> circle) & 1) == 1)
				ra(a, 1);
			else
				pb(b, a, 1);
			count--;
		}
		while (*b != 0)
		{
			pa(a, b, 1);
		}
		circle++;
	}
}
