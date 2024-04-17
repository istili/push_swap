/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.p1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 22:31:46 by istili            #+#    #+#             */
/*   Updated: 2024/04/09 00:46:54 by istili           ###   ########.fr       */
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

int		find_target_a(t_stack **a, int data)
{
	t_node *head;
	t_node	*tail;

	head = (*a)->head;
	tail = (*a)->tail;
	if (data < head->data && data > tail->data)
		return (0);
	if (data > find_max(*a)->data || data < find_min(*a)->data)
		return (ft_index((*a)->head, find_min(*a)));
	while (head->next)
	{
		if (data > head->data && data < head->next->data)
			return (ft_index((*a)->head, head->next));
		head = head->next;
	}
}

void	fill_node_b(t_node *head, t_stack **a, t_stack **b)
{
	int		indx_b;
	int		aim;
	int		size_a;
	int		size_b;
	int		nb_steps[3];

	size_a = stack_len(a);
	size_b = stack_len(b);
	aim = find_target_a(a, head->data);
	indx_b = ft_index((*b)->head, head);
	nb_steps[RARB] = min(aim, size_a - aim) + min(indx_b, size_b - indx_b) + 1;
	nb_steps[RR] = max(indx_b, aim) + 1;
	nb_steps[RRR] = max(size_a - aim, size_b - indx_b) + 1;
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

void	count_act_a(t_stack **a, t_stack **b)
{
	t_node	*head_b;
	int		size_a;
	int		size_b;

	head_b = (*b)->head;
	size_a = stack_len(a);
	size_b = stack_len(b);
	while (head_b)
	{
		fill_node_b(head_b, a, b);
		head_b = head_b->next;
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