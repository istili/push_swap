/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 02:10:40 by istili            #+#    #+#             */
/*   Updated: 2024/04/03 02:44:15 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*find_min(t_stack *stack)
{
	long	min;
	t_node	*min_node;
	t_node	*head;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	head = stack->head;
	while (head)
	{
		if (head->data < min)
		{
			min = head->data;
			min_node = head;
		}
		head = head->next;
	}
	return (min_node);
}


static t_node	*find_max(t_stack *stack)
{
	long	max;
	t_node	*max_node;
	t_node	*head;

	if (!stack)
		return (NULL);
	head = stack->head;
	max = LONG_MIN;
	while (head)
	{
		if (head->data > max)
		{
			max = head->data;
			max_node = head;
		}
		head = head->next;
	}
	return (max_node);
}

void	current_index(t_stack *stack)
{
	int		i;
	int		median;
	t_node	*head;

	i = 0;
	head = stack->head;
	if (!stack)
		return ;
	median = stack_len(&stack) / 2;
	while (head)
	{
		head->index = i;
		if (i <= median)
			head->above_median = 1;
		else
			head->above_median = 0;
		head = head->next;
		i++;
	}
}

void	set_target_a(t_stack **a, t_stack **b)
{
	t_node	*cur_b;
	t_node	*target;
	t_node	*head_a;
	long	best;

	head_a = (*a)->head;
	while (head_a)
	{
		best = LONG_MIN;
		cur_b = (*b)->head;
		while (cur_b)
		{
			if (cur_b->data < head_a->data && cur_b->data > best)
			{
				best = cur_b->data;
				target = cur_b;
			}
			cur_b = cur_b->next;
		}
		if (best == LONG_MIN)
			head_a->target = find_max(*b);
		else
			head_a->target = target;
		head_a = head_a->next;
	}
}

void	cost_analysis_a(t_stack **a, t_stack **b)
{
	int		len_a;
	int		len_b;
	t_node	*head_a;

	head_a = (*a)->head;
	len_a = stack_len(a);
	len_b = stack_len(b);
	while (head_a)
	{
		head_a->cost = head_a->index;
		if (!(head_a->above_median))
			head_a->cost = len_a - (head_a->index);
		if (head_a->target->above_median)
			head_a->cost += head_a->target->index;
		else
			head_a->cost += len_b - (head_a->target->index);
		head_a = head_a->next;
	}
}

void	set_cheapest(t_stack *stack)
{
	long	cheapest_val;
	t_node	*cheapest_node;
	t_node	*head;

	if (!stack)
		return ;
	head = stack->head;
	cheapest_val = LONG_MAX;
	while (head)
	{
		if (head->cost < cheapest_val)
		{
			cheapest_val = head->cost;
			cheapest_node = head;
		}
		head = head->next;
	}
	cheapest_node->cheapest = 1;
}
void	set_target_b(t_stack **a, t_stack **b)
{
	t_node	*cur_a;
	t_node	*target;
	t_node	*head_a;
	t_node	*head_b;
	long	best;

	head_a = (*a)->head;
	head_b = (*b)->head;
	while (*b)
	{
		best = LONG_MAX;
		cur_a = head_a;
		while (cur_a)
		{
			if (cur_a->data > head_b->data && cur_a->data < best)
			{
				best = cur_a->data;
				target = cur_a;
			}
			cur_a = cur_a->next;
		}
		if (best == LONG_MAX)
			head_a->target = find_min(*a);
		else
			head_b = target;
		head_b = head_b->next;
	}
}

void	min_on_top(t_stack **stack)
{
	while ((*stack)->head->data != find_min(*stack)->data)
	{
		if (find_min((*stack))->above_median)
			ra(stack);
		else
			rra(stack);
	}
}
