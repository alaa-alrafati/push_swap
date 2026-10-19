/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_45_nodes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalrofat <aalrofat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:48:13 by aalrofat          #+#    #+#             */
/*   Updated: 2025/12/02 12:48:44 by aalrofat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	min_is_the_head(t_stack *a)
{
	t_stack	*temp;
	int		min;

	if (a == 0)
		return (0);
	min = a->data;
	temp = a;
	while (temp != 0)
	{
		if (temp->data < min)
			min = temp->data;
		temp = temp->next;
	}
	if (a->data == min)
		return (1);
	else
		return (0);
}

void	sorted_45_nodes(t_stack **a, t_stack **b)
{
	int	count;

	count = count_stack(*a);
	if (count == 4)
	{
		while (!min_is_the_head(*a))
			ra(a, 1);
		pb(b, a, 1);
		sorted_3_nodes(a);
		pa(a, b, 1);
	}
	else if (count == 5)
	{
		while (!min_is_the_head(*a))
			ra(a, 1);
		pb(b, a, 1);
		while (!min_is_the_head(*a))
			ra(a, 1);
		pb(b, a, 1);
		sorted_3_nodes(a);
		if ((*b)->data < (*b)->next->data)
			sb(b, 1);
		pa(a, b, 1);
		pa(a, b, 1);
	}
}
