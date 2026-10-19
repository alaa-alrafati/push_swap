/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_3_nodes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalrofat <aalrofat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:47:22 by aalrofat          #+#    #+#             */
/*   Updated: 2025/12/02 12:47:53 by aalrofat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	t_stack	*find_the_max(t_stack *a)
{
	t_stack	*max;

	max = a;
	while (a != 0)
	{
		if (a->data > max->data)
			max = a;
		a = a->next;
	}
	return (max);
}

void	sorted_3_nodes(t_stack **a)
{
	t_stack	*max;

	max = find_the_max(*a);
	if (*a == max)
		ra(a, 1);
	else if ((*a)->next == max)
		rra(a, 1);
	if ((*a)->data > (*a)->next->data)
		sa(a, 1);
}
