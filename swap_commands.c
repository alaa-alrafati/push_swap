/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalrofat <aalrofat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:39:51 by aalrofat          #+#    #+#             */
/*   Updated: 2025/12/02 12:43:39 by aalrofat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	swap(t_stack **begin_list)
{
	t_stack	*temp1;
	t_stack	*temp2;
	t_stack	*temp3;

	if (begin_list == 0 || *begin_list == 0 || (*begin_list)->next == 0)
		return ;
	temp1 = *begin_list;
	temp2 = (*begin_list)->next;
	temp3 = (*begin_list)->next->next;
	temp2->prev = NULL;
	temp2->next = temp1;
	temp1->prev = temp2;
	temp1->next = temp3;
	if (temp3 != 0)
		temp3->prev = temp1;
	*begin_list = temp2;
}

void	sa(t_stack **a, int print)
{
	swap(a);
	if (print == 1)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, int print)
{
	swap(b);
	if (print == 1)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, int print)
{
	swap(a);
	swap(b);
	if (print == 1)
		write(1, "ss\n", 3);
}
