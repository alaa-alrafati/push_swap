/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalrofat <aalrofat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:46:06 by aalrofat          #+#    #+#             */
/*   Updated: 2025/12/02 12:46:51 by aalrofat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	push_to(t_stack **dest, t_stack **src)
{
	t_stack	*temp;

	if (src == 0 || *src == 0)
		return ;
	temp = *src;
	*src = (*src)->next;
	if (*src != 0)
		(*src)->prev = NULL;
	temp->prev = NULL;
	if (*dest == 0)
	{
		*dest = temp;
		temp->next = NULL;
	}
	else if (*dest != 0)
	{
		temp->next = *dest;
		(*dest)->prev = temp;
		*dest = temp;
	}
}

void	pa(t_stack **a, t_stack **b, int print)
{
	push_to(a, b);
	if (print == 1)
		write(1, "pa\n", 3);
}

void	pb(t_stack **b, t_stack **a, int print)
{
	push_to(b, a);
	if (print == 1)
		write(1, "pb\n", 3);
}
