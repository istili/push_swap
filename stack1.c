/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:05:30 by istili            #+#    #+#             */
/*   Updated: 2024/04/19 15:11:15 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rrr(t_stack **a, t_stack **b, t_node *cheapest)
{
	while ((*a)->head->data != cheapest->data
		|| find_target(b, cheapest->data))
	{
		if ((*a)->head->data == cheapest->data)
			break ;
		if (!find_target(b, cheapest->data))
			break ;
		rrr(a, b);
	}
	while ((*a)->head->data != cheapest->data)
	{
		if ((*a)->head->data == cheapest->data)
			break ;
		rra(a);
	}
	while (find_target(b, cheapest->data))
	{
		if (!find_target(b, cheapest->data))
			break ;
		rrb(b);
	}
	pb(a, b);
}

void	do_rr(t_stack **a, t_stack **b, t_node *cheapest)
{
	while ((*a)->head->data != cheapest->data || find_target(b, cheapest->data))
	{
		if ((*a)->head->data == cheapest->data)
			break ;
		if (!find_target(b, cheapest->data))
			break ;
		rr(a, b);
	}
	while ((*a)->head->data != cheapest->data)
	{
		if ((*a)->head->data == cheapest->data)
			break ;
		ra(a);
	}
	while (find_target(b, cheapest->data))
	{
		if (!find_target(b, cheapest->data))
			break ;
		rb(b);
	}
	pb(a, b);
}

static void	ft_continue(t_stack **a, t_stack **b, t_node *cheapest)
{
	if (find_target(b, cheapest->data) > stack_len(b) / 2)
	{
		while (find_target(b, cheapest->data) != 0)
		{
			if (!find_target(b, cheapest->data))
				break ;
			rrb(b);
		}
	}
	else
	{
		while (find_target(b, cheapest->data) != 0)
		{
			if (!find_target(b, cheapest->data))
				break ;
			rb(b);
		}
	}
}

void	do_rarb(t_stack **a, t_stack **b, t_node *cheapest)
{
	int	len;
	int	mid;

	len = stack_len(a);
	mid = len / 2;
	if (ft_index((*a)->head, cheapest) > mid)
	{
		while ((*a)->head->data != cheapest->data)
		{
			if ((*a)->head->data == cheapest->data)
				break ;
			rra(a);
		}
	}
	else
	{
		while ((*a)->head->data != cheapest->data)
		{
			if ((*a)->head->data == cheapest->data)
				break ;
			ra(a);
		}
	}
	ft_continue(a, b, cheapest);
	pb(a, b);
}
