/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 04:33:37 by istili            #+#    #+#             */
/*   Updated: 2024/05/24 17:05:28 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "mandatory.h"

static void	make_it_top(t_stack	**stack)
{
	t_node	*head;
	t_node	*tail;
	int		min;

	head = (*stack)->head;
	tail = (*stack)->tail;
	min = find_small(stack);
	if (min == head->next->data)
	{
		sa(stack);
		return ;
	}
	if (ft_index((*stack)->head, find_min(*stack)) > stack_len(stack) / 2)
		while ((*stack)->head->data != find_min(*stack)->data)
			rra(stack);
	else
		while ((*stack)->head->data != find_min(*stack)->data)
			ra(stack);
}

void	sort_four(t_stack **a, t_stack **b)
{
	t_node	*head;

	head = (*a)->head;
	make_it_top(a);
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_stack **a, t_stack **b)
{
	t_node	*head;

	head = (*a)->head;
	make_it_top(a);
	pb(a, b);
	make_it_top(a);
	pb(a, b);
	sort_three(a);
	pa(a, b);
	pa(a, b);
}

static void	sort_three_helper(t_stack **a, t_node *head)
{
	if (head->data < head->next->data
		&& head->data < head->next->next->data
		&& head->next->data > head->next->next->data)
	{
		sa(a);
		ra(a);
		return ;
	}
	if (head->data < head->next->data
		&& head->data > head->next->next->data)
	{
		rra(a);
		return ;
	}
}

void	sort_three(t_stack **a)
{
	t_node	*head;

	head = (*a)->head;
	if (head->data > head->next->data && head->data < head->next->next->data)
	{
		sa(a);
		return ;
	}
	if (head->data > head->next->data && head->data > head->next->next->data
		&& head->next->data > head->next->next->data)
	{
		sa(a);
		rra(a);
		return ;
	}
	if (head->data > head->next->data && head->data > head->next->next->data
		&& head->next->data < head->next->next->data)
	{
		ra(a);
		return ;
	}
	sort_three_helper(a, head);
}
