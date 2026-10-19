/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalrofat <aalrofat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:21:23 by aalrofat          #+#    #+#             */
/*   Updated: 2025/12/02 12:36:38 by aalrofat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_stack
{
	int				data;
	int				index;

	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

char	**ft_split(char const *s, char c);
void	free_splitted(char **splitted);
void	create_stack(t_stack **a, char **argv, char **splitted);
int		count_stack(t_stack *stack);
void	sorted_3_nodes(t_stack **a);
void	sorted_45_nodes(t_stack **a, t_stack **b);
void	sort_stack(t_stack **a, t_stack **b);
void	radix_algorathem(t_stack **a, t_stack **b);

void	create_array(t_stack *a);
void	fill_array(t_stack *a, int *array);
void	sort_array(int *array, int len);
void	index_stack(t_stack *a, int *array, int len);

int		only_spaces_error(char *argv);
void	free_errors(t_stack **a, char **splitted);
void	free_stack(t_stack **a);
int		inavlid_input(char *str);
int		duplicates_error(t_stack *a, int num);

void	sa(t_stack **a, int print);
void	sb(t_stack **b, int print);
void	ss(t_stack **a, t_stack **b, int print);
void	ra(t_stack **a, int print);
void	rb(t_stack **b, int print);
void	rr(t_stack **a, t_stack **b, int print);
void	rra(t_stack **a, int print);
void	rrb(t_stack **b, int print);
void	rrr(t_stack **a, t_stack **b, int print);
void	pa(t_stack **a, t_stack **b, int print);
void	pb(t_stack **b, t_stack **a, int print);

#endif
