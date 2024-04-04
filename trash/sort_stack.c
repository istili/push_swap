/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 20:53:56 by istili            #+#    #+#             */
/*   Updated: 2024/04/03 02:22:09 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_node_a(t_stack **a, t_stack **b)
{
	current_index(*a);
	current_index(*b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(*a);
}

t_node	*get_cheapest(t_stack *stack)
{
	t_node	*head;

	head = stack->head;
	if (!stack)
		return (NULL);
	while (head)
	{
		if (head->cheapest)
			return (head);
		head = head->next;
	}
	return (NULL);
}

static void	rotate_both(t_stack **a, t_stack **b, t_node *chep_node)
{
	t_node	*head_a;
	t_node	*head_b;

	head_a = (*a)->head;
	head_b = (*b)->head;
	while (head_b != chep_node->target && head_a != chep_node)
	{
		rr(a, b);
		current_index(*a);
		current_index(*b);
	}
}

static void	rev_rotate_both(t_stack **a, t_stack **b, t_node *chep_node)
{
	t_node	*head_b;
	t_node	*head_a;

	head_b = (*b)->head;
	head_a = (*a)->head;
	while (head_b != chep_node->target && head_a != chep_node)
		rr(a, b);
	current_index(*a);
	current_index(*b);
}

static void	prep_for_push(t_stack **stack, t_node *top, char name)
{
	t_node	*head;

	head = (*stack)->head;
	while (head != top)
	{
		if (name == 'a')
		{
			if (top->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (name == 'b')
		{
			if (top->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

static void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_node	*chep_node;

	chep_node = get_cheapest(*a);
	if (chep_node->above_median && chep_node->target->above_median) // above
		rotate_both(a, b, chep_node);
	else if (!(chep_node->above_median) && !(chep_node->target->above_median)) //below
		rev_rotate_both(a, b, chep_node);
	prep_for_push(a, chep_node, 'a');
	prep_for_push(b, chep_node->target, 'b');
	pb(a, b);
}

static void	move_b_to_a(t_stack **a, t_stack **b)
{
	t_node	*head_b;

	head_b = (*b)->head;
	prep_for_push(a, head_b->target, 'a');
	pa(a, b);
}

void	init_node_b(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	set_target_b(&a, &b);
}

void	sort_stack(t_stack **a, t_stack **b)
{
	int	len;

	len = stack_len(a);
	if (len > 3 && !sorted(a))
		pb(a, b);
	len--;
	if (len > 3 && !sorted(a))
		pb(a, b);
	len--;
	while (len > 3 && !sorted(a))
	{
		init_node_a(a, b);
		move_a_to_b(a, b);
		len--;
	}
	easy(a);
	while (*b)
	{
		init_node_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}
