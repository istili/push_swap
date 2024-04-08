/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 20:40:33 by istili            #+#    #+#             */
/*   Updated: 2024/04/08 04:20:13 by istili           ###   ########.fr       */
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
	return (min_node);
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
	return (max_node);
}

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

void	push_cheapest(t_stack **a, t_stack **b, t_node *cheapest)
{
	if (cheapest->act == RARB)
		do_rarb(a, b, cheapest);
	else if (cheapest->act == RR)
		do_rr(a, b, cheapest);
	else if (cheapest->act == RRR)
		do_rrr(a, b, cheapest);
}

void	sort_stack(t_stack **a, t_stack **b)
{
	t_node	*cheapest;

	pb(a, b);
	pb(a, b);
	puts("\nstack a:\n");
	print_stack(a);
	puts("\nstack b:\n");
	print_stack(b);
	while (stack_len(a) > 3)
	{
		count_act(a, b);
		puts("\nstack a:\n");
		print_stack(a);
		puts("\nstack b:\n");
		print_stack(b);
		cheapest = find_cheapest(a);
		printf("cheapest: %d\n", cheapest->data);
		push_cheapest(a, b, cheapest);
		puts("\nstack a:\n");
		print_stack(a);
		puts("\nstack b:\n");
		print_stack(b);
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