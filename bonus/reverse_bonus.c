/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:38:14 by istili            #+#    #+#             */
/*   Updated: 2024/04/27 11:04:04 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	reverse(t_stack **stack)
{
	t_node	*head;
	t_node	*tail;

	if ((*stack)->head != (*stack)->tail)
	{
		tail = (*stack)->tail;
		head = (*stack)->head;
		(*stack)->tail = (*stack)->tail->prv;
		(*stack)->tail->next = NULL;
		tail->prv = NULL;
		tail->next = head;
		head->prv = tail;
		(*stack)->head = tail;
	}
}

void	rra(t_stack **a)
{
	if (stack_len(a) < 2)
		return ;
	reverse(a);
}

void	rrb(t_stack **b)
{
	if (stack_len(b) < 2)
		return ;
	reverse(b);
}

void	rrr(t_stack **a, t_stack **b)
{
	if (stack_len(a) < 2 && stack_len(b) < 2)
		return ;
	if (a)
		reverse(a);
	if (b)
		reverse(b);
}
