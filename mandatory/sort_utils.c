/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_500.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:59:08 by istili            #+#    #+#             */
/*   Updated: 2024/05/24 17:14:05 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "mandatory.h"

int	find_target_a(t_stack **a, int data)
{
	t_node	*head;
	t_node	*tail;

	head = (*a)->head;
	tail = (*a)->tail;
	if (data > find_max(*a)->data || data < find_min(*a)->data)
		return (ft_index((*a)->head, find_min(*a)));
	if (data < head->data && data > tail->data)
		return (0);
	while (head->next)
	{
		if (data > head->data && data < head->next->data)
			return (ft_index((*a)->head, head->next));
		head = head->next;
	}
	return (0);
}

int	find_small(t_stack **stack)
{
	t_node	*head;
	int		min;

	head = (*stack)->head;
	min = (*stack)->head->data;
	while (head)
	{
		if (min > head->data)
			min = head->data;
		head = head->next;
	}
	return (min);
}

t_node	*find_cheapest(t_stack **a)
{
	t_node	*head_a;
	t_node	*cheapest;

	head_a = (*a)->head;
	cheapest = head_a;
	while (head_a)
	{
		if (head_a->count <= cheapest->count)
			cheapest = head_a;
		head_a = head_a->next;
	}
	return (cheapest);
}

void	push_cheapest_a(t_stack **a, t_stack **b, t_node *cheapest)
{
	if (cheapest->act == RARB)
		do_rarb_a(a, b, cheapest);
	else if (cheapest->act == RR)
		do_rr_a(a, b, cheapest);
	else if (cheapest->act == RRR)
		do_rrr_a(a, b, cheapest);
}
