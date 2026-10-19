/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalrofat <aalrofat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:33:23 by aalrofat          #+#    #+#             */
/*   Updated: 2025/12/02 12:40:51 by aalrofat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	t_stack	*the_last_node(t_stack *begin_list)
{
	if (begin_list == 0)
		return (0);
	while (begin_list->next != 0)
		begin_list = begin_list->next;
	return (begin_list);
}

static	void	add_node(t_stack **a, int n)
{
	t_stack	*node;
	t_stack	*last_node;

	node = NULL;
	node = (t_stack *)malloc(sizeof(t_stack));
	if (node == 0)
		return ;
	node->data = n;
	node->next = NULL;
	if (*a == 0)
	{
		*a = node;
		node->prev = NULL;
	}
	else
	{
		last_node = the_last_node(*a);
		last_node->next = node;
		node->prev = last_node;
	}
}

static	long	ft_atoi(const char *nptr)
{
	long	fnum;
	int		signal;
	int		x;

	x = 0;
	signal = 1;
	fnum = 0;
	while ((nptr[x] >= 9 && nptr[x] <= 13) || (nptr[x] == 32))
		x++;
	if (nptr[x] == '+' || nptr[x] == '-')
	{
		if (nptr[x] == '-')
			signal *= -1;
		x++;
	}
	while (nptr[x] >= 48 && nptr[x] <= 57)
	{
		fnum = fnum * 10 + (nptr[x] - '0');
		x++;
	}
	return (fnum * signal);
}

void	create_stack(t_stack **a, char **argv, char **splitted)
{
	long	num;
	int		x;

	x = 0;
	while (argv[x] != NULL)
	{
		if (inavlid_input(argv[x]))
			free_errors(a, splitted);
		num = ft_atoi(argv[x]);
		if (num > INT_MAX || num < INT_MIN)
			free_errors(a, splitted);
		if (duplicates_error(*a, (int)num))
			free_errors(a, splitted);
		add_node(a, (int)num);
		x++;
	}
}
