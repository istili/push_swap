/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 20:40:33 by istili            #+#    #+#             */
/*   Updated: 2024/04/04 01:48:03 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	index(t_node *head, t_node *node)
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

static t_node	*find_min(t_stack *stack) // 5 6 2 3 -11 //min:5
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
	return (tail);
}

static t_node	*find_max(t_stack *stack) // -1 90 100 6 33 
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
	return (head);
}

int	find_target(t_stack **b, int data)
{
	t_node	*head;
	t_node	*tail;

	head = (*b)->head;
	tail = (*b)->tail;
	if (data > find_max(*b)->data || data < find_min(*b)->data)
		return (index((*b)->head, find_max(*b)->data));
	if (data > head->data && data < tail->data)
		return (0);
	while (head)
	{
		if (head->data > data && data > head->next->data)
			return (index((*b)->head, head->next));
		head = head->next;
	}
}

t_node	*fin_cheap(t_stack **a, t_stack **b)
{
	t_node	*head_a;
	t_node	*head_b;

	head_a = (*a)->head;
	head_b = (*b)->head;
	if (head_a->target == head_b)
		return (head_b);
	while (head_a)
	{
		
	}
}

void	sort_stack(t_stack **a, t_stack **b)
{
	int		len;
	t_node	*head_a;

	len = stack_len(a);
	pb(a, b);
	len--;
	pb(a, b);
	len--;
	head_a = (*a)->head;
	while (len > 3)
	{
		find_target(b, head_a->data);
		find_cheap(a, b);
		len--;
		head_a = head_a->next;
	}
	easy(a);
}
//stack a:
// 3
// 99
// -91000000
// 33

// stack b:
// 55
// 7
// 5
// 3
// 2
// 555