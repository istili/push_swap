/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 01:31:21 by istili            #+#    #+#             */
/*   Updated: 2024/04/27 14:27:02 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "mandatory.h"

void	do_rrr_a(t_stack **a, t_stack**b, t_node*cheapest)
{
	while ((*b)->head->data != cheapest->data
		|| find_target_a(a, cheapest->data))
	{
		if ((*b)->head->data == cheapest->data)
			break ;
		if (!find_target_a(a, cheapest->data))
			break ;
		rrr(a, b);
	}
	while ((*b)->head->data != cheapest->data)
	{
		if ((*b)->head->data == cheapest->data)
			break ;
		rrb(b);
	}
	while (find_target_a(a, cheapest->data))
	{
		if (!find_target_a(a, cheapest->data))
			break ;
		rra(a);
	}
	pa(a, b);
}

void	do_rr_a(t_stack **a, t_stack **b, t_node *cheapest)
{
	while ((*b)->head->data != cheapest->data
		|| find_target_a(a, cheapest->data))
	{
		if ((*b)->head->data == cheapest->data)
			break ;
		if (!find_target_a(a, cheapest->data))
			break ;
		rr(a, b);
	}
	while ((*b)->head->data != cheapest->data)
	{
		if ((*b)->head->data == cheapest->data)
			break ;
		rb(b);
	}
	while (find_target_a(a, cheapest->data))
	{
		if (!find_target_a(a, cheapest->data))
			break ;
		ra(a);
	}
	pa(a, b);
}

static void	ft_continue(t_stack **a, t_node *cheapest)
{
	if (find_target_a(a, cheapest->data) > stack_len(a) / 2)
	{
		while (find_target_a(a, cheapest->data))
		{
			if (!find_target_a(a, cheapest->data))
				break ;
			rra(a);
		}
	}
	else
	{
		while (find_target_a(a, cheapest->data))
		{
			if (!find_target_a(a, cheapest->data))
				break ;
			ra(a);
		}
	}
}

void	do_rarb_a(t_stack **a, t_stack **b, t_node *cheapest)
{
	int	mid;

	mid = stack_len(b) / 2;
	if (ft_index((*b)->head, cheapest) > mid)
	{
		while ((*b)->head->data != cheapest->data)
		{
			if ((*b)->head->data == cheapest->data)
				break ;
			rrb(b);
		}
	}
	else
	{
		while ((*b)->head->data != cheapest->data)
		{
			if ((*b)->head->data == cheapest->data)
				break ;
			rb(b);
		}
	}
	ft_continue(a, cheapest);
	pa(a, b);
}
