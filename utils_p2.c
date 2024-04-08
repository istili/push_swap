/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_p2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 01:31:21 by istili            #+#    #+#             */
/*   Updated: 2024/04/08 03:40:52 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rrr(t_stack **a, t_stack **b, t_node *cheapest)
{
	while ((*a)->head->data != cheapest->data
		|| find_target(b, cheapest->data))
		rrr(a, b);
	while ((*a)->head->data != cheapest->data)
		rra(a);
	while (find_target(b, cheapest->data))
		rrb(b);
	pb(a, b);
}

void	do_rr(t_stack **a, t_stack **b, t_node *cheapest)
{
	while ((*a)->head->data != cheapest->data
		|| find_target(b, cheapest->data))
		rr(a, b);
	while ((*a)->head->data != cheapest->data)
		ra(a);
	while (find_target(b, cheapest->data))
		rb(b);
	pb(a, b);
}

void	do_rarb(t_stack **a, t_stack **b, t_node *cheapest)
{
	int	len;
	int	mid;

	len = stack_len(a);
	mid = len / 2;
	if (ft_index((*a)->head, cheapest) > mid)
		while ((*a)->head->data != cheapest->data)
			rra(a);
	else
		while ((*a)->head->data != cheapest->data)
			ra(a);
	if (find_target(b, cheapest->data) > mid)
		while (find_target(b, cheapest->data) != 0)
			rrb(b);
	else
		while (find_target(b, cheapest->data) != 0)
			rb(b);
	pb(a, b);
}
