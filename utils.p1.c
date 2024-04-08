/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.p1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 22:31:46 by istili            #+#    #+#             */
/*   Updated: 2024/04/08 04:14:24 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

int	min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

void	fill_node(t_node *head, t_stack **a, t_stack **b)
{
	int		indx_a;
	int		aim;
	int		size_a;
	int		size_b;
	int		nb_steps[3];

	size_a = stack_len(a);
	size_b = stack_len(b);
	aim = find_target(b, head->data);
	indx_a = ft_index((*a)->head, head);
	nb_steps[RARB] = min(indx_a, size_a - indx_a) + min(aim, size_b - aim) + 1;
	nb_steps[RR] = max(indx_a, aim) + 1;
	nb_steps[RRR] = max(size_a - indx_a, size_b - aim) + 1;
	if (nb_steps[RARB] <= nb_steps[RR]
		&& nb_steps[RARB] <= nb_steps[RRR])
	{
		head->count = nb_steps[RARB];
		head->act = RARB;
	}
	else if (nb_steps[RR] <= nb_steps[RARB]
		&& nb_steps[RR] <= nb_steps[RRR])
	{
		head->count = nb_steps[RR];
		head->act = RR;
	}
	else if (nb_steps[RRR] <= nb_steps[RR]
		&& nb_steps[RRR] <= nb_steps[RARB])
	{
		head->count = nb_steps[RRR];
		head->act = RRR;
	}
}

void	count_act(t_stack **a, t_stack **b)
{
	t_node	*head_a;
	int		size_a;
	int		size_b;

	head_a = (*a)->head;
	size_a = stack_len(a);
	size_b = stack_len(b);
	while (head_a)
	{
		fill_node(head_a, a, b);
		head_a = head_a->next;
	}
}
// stack a:
// 5
// 99
// 2
//
// stack b:
// 
//