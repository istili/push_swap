/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 02:32:34 by istili            #+#    #+#             */
/*   Updated: 2024/04/27 19:59:30 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "mandatory.h"

static void	rotate(t_stack **a)
{
	t_node	*head;
	t_node	*tail;

	if ((*a)->head != (*a)->tail)
	{
		head = (*a)->head;
		tail = (*a)->tail;
		(*a)->head = (*a)->head->next;
		(*a)->head->prv = NULL;
		head->prv = tail;
		head->next = NULL;
		tail->next = head;
		(*a)->tail = head;
	}
}

void	rb(t_stack **b)
{
	if (stack_len(b) < 2)
		return ;
	rotate(b);
	write(1, "rb\n", 3);
}

void	ra(t_stack **a)
{
	if (stack_len(a) < 2)
		return ;
	rotate(a);
	write(1, "ra\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	if (stack_len(a) < 2 && stack_len(b) < 2)
		return ;
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
