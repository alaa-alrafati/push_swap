/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalrofat <aalrofat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:10:14 by aalrofat          #+#    #+#             */
/*   Updated: 2025/12/02 12:38:16 by aalrofat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_splitted(char **splitted)
{
	int	x;

	x = 0;
	while (splitted[x] != NULL)
	{
		free(splitted[x]);
		x++;
	}
	free(splitted);
}

static	int	does_stack_a_sorted(t_stack *a)
{
	if (a == 0)
		return (1);
	while (a->next != 0)
	{
		if (a->data > a->next->data)
			return (0);
		a = a->next;
	}
	return (1);
}

int	count_stack(t_stack *stack)
{
	int	count;

	if (stack == 0)
		return (0);
	count = 0;
	while (stack != 0)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

void	sort_stack(t_stack **a, t_stack **b)
{
	if (!does_stack_a_sorted(*a))
	{
		if (count_stack(*a) == 2)
			sa(a, 1);
		else if (count_stack(*a) == 3)
			sorted_3_nodes(a);
		else if (count_stack(*a) == 4 || count_stack(*a) == 5)
			sorted_45_nodes(a, b);
		else
		{
			create_array(*a);
			radix_algorathem(a, b);
		}
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**splitted;

	a = NULL;
	b = NULL;
	splitted = NULL;
	if (argc == 1)
		return (0);
	else if (argc == 2 && (argv[1][0] == '\0' || only_spaces_error(argv[1])))
		free_errors(&a, splitted);
	else if (argc == 2)
	{
		splitted = ft_split(argv[1], ' ');
		create_stack(&a, splitted, splitted);
	}
	else
		create_stack(&a, argv + 1, NULL);
	if (!does_stack_a_sorted(a))
		sort_stack(&a, &b);
	free_stack(&a);
	if (splitted != NULL)
		free_splitted(splitted);
	return (0);
}
