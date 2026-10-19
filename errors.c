/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalrofat <aalrofat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:35:38 by aalrofat          #+#    #+#             */
/*   Updated: 2025/12/02 12:42:10 by aalrofat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	only_spaces_error(char *argv)
{
	int	x;

	x = 0;
	while (argv[x] != '\0')
	{
		if (argv[x] != ' ')
			return (0);
		x++;
	}
	return (1);
}

void	free_stack(t_stack **a)
{
	t_stack	*temp;
	t_stack	*current;

	if (a == 0 || *a == 0)
		return ;
	current = *a;
	while (current != 0)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*a = NULL;
}

void	free_errors(t_stack **a, char **splitted)
{
	free_stack(a);
	if (splitted != NULL)
		free_splitted(splitted);
	write(2, "Error\n", 6);
	exit(1);
}

int	inavlid_input(char *str)
{
	int	x;

	x = 0;
	if (!((str[x] == '+' || str[x] == '-') || (str[x] >= '0' && str[x] <= '9')))
		return (1);
	if ((str[x] == '+' || str[x] == '-')
		&& !(str[x + 1] >= '0' && str[x + 1] <= '9'))
		return (1);
	x++;
	while (str[x] != '\0')
	{
		if (!(str[x] >= '0' && str[x] <= '9'))
			return (1);
		x++;
	}
	return (0);
}

int	duplicates_error(t_stack *a, int num)
{
	if (a == 0)
		return (0);
	while (a != 0)
	{
		if (a->data == num)
			return (1);
		a = a->next;
	}
	return (0);
}
