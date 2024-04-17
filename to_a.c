/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_a.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:14:51 by istili            #+#    #+#             */
/*   Updated: 2024/04/17 10:42:50 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	mn(int a, int b)
{
	if (a >= b)
		return (b);
	return (a);
}

int	mx(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

int	find_target_a(t_stack **a, int data)
{
	t_node	*head;
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
	return (0);
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
	nb_steps[RARB] = mn(aim, size_a - aim) + mn(indx_b, size_b - indx_b) + 1;
	nb_steps[RR] = mx(indx_b, aim) + 1;
	nb_steps[RRR] = mx(size_a - aim, size_b - indx_b) + 1;
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

	head_b = (*b)->head;
	while (head_b)
	{
		fill_node_b(head_b, a, b);
		head_b = head_b->next;
	}
}
