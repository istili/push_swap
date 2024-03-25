/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 02:32:34 by istili            #+#    #+#             */
/*   Updated: 2024/03/21 21:23:54 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		tail = head;
	}
}

void	rb(t_stack **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	ra(t_stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
}