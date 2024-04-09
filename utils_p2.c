/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_p2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 01:31:21 by istili            #+#    #+#             */
/*   Updated: 2024/04/09 01:50:06 by istili           ###   ########.fr       */
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
		rrr(a, b);
	}
	while ((*a)->head->data != cheapest->data)
		rra(a);
	while (find_target(b, cheapest->data))
		rrb(b);
	pb(a, b);
}

void	do_rr(t_stack **a, t_stack **b, t_node *cheapest)
{
	while ((*a)->head->data != cheapest->data || find_target(b, cheapest->data))
	{
		if ((*a)->head->data == cheapest->data
			|| !find_target(b, cheapest->data))
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
		printf("%d\n", find_target(b, cheapest->data));
		if (find_target(b, cheapest->data) == 0)
			break ;
		rb(b);
	}
	pb(a, b);
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
	if (find_target(b, cheapest->data) > mid)
	{
		while (find_target(b, cheapest->data) != 0)
		{
			if (find_target(b, cheapest->data) == 0)
				break ;
			rrb(b);
		}
	}
	else
	{
		while (find_target(b, cheapest->data) != 0)
		{
			if (find_target(b, cheapest->data) == 0)
				break ;
			rb(b);
		}
	}
	pb(a, b);
}
