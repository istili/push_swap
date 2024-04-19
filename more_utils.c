/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:59:08 by istili            #+#    #+#             */
/*   Updated: 2024/04/19 15:12:21 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_target(t_stack **b, int data)
{
	t_node	*head;
	t_node	*tail;

	head = (*b)->head;
	tail = (*b)->tail;
	if (data > find_max(*b)->data || data < find_min(*b)->data)
		return (ft_index((*b)->head, find_max(*b)));
	if (data > head->data && data < tail->data)
		return (0);
	while (head->next)
	{
		if (data < head->data && data > head->next->data)
			return (ft_index((*b)->head, head->next));
		head = head->next;
	}
	return (0);
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

int	find_smal(t_stack **stack)
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
