/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:32:02 by istili            #+#    #+#             */
/*   Updated: 2024/04/25 17:37:32 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_index(t_node *head, t_node *node)
{
	int	i;

	i = 0;
	while (head != node)
	{
		i++;
		head = head->next;
	}
	return (i);
}

t_node	*find_min(t_stack *stack)
{
	int		min;
	t_node	*tail;
	t_node	*min_node;

	tail = stack->tail;
	min = tail->data;
	min_node = tail;
	while (tail)
	{
		if (min > tail->data)
		{
			min_node = tail;
			min = tail->data;
		}
		tail = tail->prv;
	}
	return (min_node);
}

t_node	*find_max(t_stack *stack)
{
	int		max;
	t_node	*head;
	t_node	*max_node;

	head = stack->head;
	max = head->data;
	max_node = head;
	while (head)
	{
		if (max < head->data)
		{
			max_node = head;
			max = head->data;
		}
		head = head->next;
	}
	return (max_node);
}
