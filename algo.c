/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 04:33:37 by istili            #+#    #+#             */
/*   Updated: 2024/04/17 16:43:25 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	make_it_top(t_stack	**stack)
{
	t_node	*head;
	t_node	*tail;
	int		min;

	head = (*stack)->head;
	tail = (*stack)->tail;
	min = find_smal(stack);
	if (min == head->next->data)
	{
		sa(stack);
		return ;
	}
	if (min == tail->data)
	{
		rra(stack);
		return ;
	}
	if (min == tail->prv->data)
	{
		rra(stack);
		rra(stack);
		return ;
	}
	if (ft_index((*stack)->head, find_min(*stack)) > stack_len(stack) / 2)
		while ((*stack)->head->data != find_min(*stack)->data)
			rra(stack);
	else
		while ((*stack)->head->data != find_min(*stack)->data)
			ra(stack);
}

void	sort_for(t_stack **a, t_stack **b) // 4 2 5 <-/1 ? /-> 4  5 2 1
{
	t_node	*head;

	head = (*a)->head;
	make_it_top(a);
	pb(a, b);
	easy(a);
	print_stack(a);
	pa(a, b);
}

void	sort_fiv(t_stack **a, t_stack **b)
{
	t_node	*head;

	head = (*a)->head;
	make_it_top(a);
	pb(a, b);
	make_it_top(a);
	pb(a, b);
	easy(a);
	pa(a, b);
	pa(a, b);
}

void	easy(t_stack **a)
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
	if (head->data < head->next->data && head->data < head->next->next->data
		&& head->next->data > head->next->next->data)
	{
		sa(a);
		ra(a);
		return ;
	}
	if (head->data < head->next->data && head->data > head->next->next->data)
	{
		rra(a);
		return ;
	}
}
