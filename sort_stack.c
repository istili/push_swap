/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 20:40:33 by istili            #+#    #+#             */
/*   Updated: 2024/04/19 14:50:22 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_cheapest(t_stack **a)
{
	t_node	*head_a;
	t_node	*cheapest;

	head_a = (*a)->head;
	cheapest = head_a;
	while (head_a)
	{
		if (head_a->count <= cheapest->count)
			cheapest = head_a;
		head_a = head_a->next;
	}
	return (cheapest);
}

void	push_cheapest(t_stack **a, t_stack **b, t_node *cheapest)
{
	if (cheapest->act == RARB)
		do_rarb(a, b, cheapest);
	else if (cheapest->act == RR)
		do_rr(a, b, cheapest);
	else if (cheapest->act == RRR)
		do_rrr(a, b, cheapest);
}

void	push_cheapest_a(t_stack **a, t_stack **b, t_node *cheapest)
{
	if (cheapest->act == RARB)
		do_rarb_a(a, b, cheapest);
	else if (cheapest->act == RR)
		do_rr_a(a, b, cheapest);
	else if (cheapest->act == RRR)
		do_rrr_a(a, b, cheapest);
}

void	sort_stack(t_stack **a, t_stack **b)
{
	t_node	*cheapest;
	int		medain_data;
	int		size;

	size = -1;
	medain_data = get_medain(a);
	while (++size < stack_len(a))
		push_to_b(a, b, medain_data);
	while (stack_len(a) > 3)
		pb(a, b);
	easy(a);
	while (stack_len(b) > 0)
	{
		count_act_a(a, b);
		cheapest = find_cheapest(b);
		push_cheapest_a(a, b, cheapest);
	}
	if (ft_index((*a)->head, find_min(*a)) > stack_len(a) / 2)
		while ((*a)->head->data != find_min(*a)->data)
			rra(a);
	else
		while ((*a)->head->data != find_min(*a)->data)
			ra(a);
}
