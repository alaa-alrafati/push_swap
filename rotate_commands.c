/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalrofat <aalrofat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:44:15 by aalrofat          #+#    #+#             */
/*   Updated: 2025/12/02 12:44:25 by aalrofat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	rotate(t_stack **begin_list)
{
	t_stack	*first;
	t_stack	*last;

	if (begin_list == 0 || *begin_list == 0 || (*begin_list)->next == 0)
		return ;
	first = *begin_list;
	last = *begin_list;
	while (last->next != 0)
		last = last->next;
	last->next = first;
	first->prev = last;
	*begin_list = first->next;
	(*begin_list)->prev = NULL;
	first->next = NULL;
}

void	ra(t_stack **a, int print)
{
	rotate(a);
	if (print == 1)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, int print)
{
	rotate(b);
	if (print == 1)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, int print)
{
	rotate(a);
	rotate(b);
	if (print == 1)
		write(1, "rr\n", 3);
}
