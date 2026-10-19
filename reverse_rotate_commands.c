/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_commands.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalrofat <aalrofat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:45:26 by aalrofat          #+#    #+#             */
/*   Updated: 2025/12/02 12:45:41 by aalrofat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	reverse_rotate(t_stack **begin_list)
{
	t_stack	*last;
	t_stack	*before_last;

	if (begin_list == 0 || *begin_list == 0 || (*begin_list)->next == 0)
		return ;
	last = *begin_list;
	before_last = NULL;
	while (last->next != 0)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	last->next = *begin_list;
	(*begin_list)->prev = last;
	last->prev = NULL;
	*begin_list = last;
}

void	rra(t_stack **a, int print)
{
	reverse_rotate(a);
	if (print == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, int print)
{
	reverse_rotate(b);
	if (print == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, int print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (print == 1)
		write(1, "rrr\n", 4);
}
