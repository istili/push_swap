/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 20:40:33 by istili            #+#    #+#             */
/*   Updated: 2024/05/24 17:17:25 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "mandatory.h"

void	sort(t_stack **a, t_stack **b)
{
	if (!sorted(a))
	{
		if (stack_len(a) == 2)
			sa(a);
		else if (stack_len(a) == 3)
			sort_three(a);
		else if (stack_len(a) == 4)
			sort_four(a, b);
		else if (stack_len(a) == 5)
			sort_five(a, b);
		else
			sort_stack(a, b);
	}
}

void	sort_500(t_stack **a, t_stack **b)
{
	t_node	*cheapest;
	int		median_data;
	int		size;

	size = -1;
	median_data = get_median(a);
	while (++size < stack_len(a))
		push_to_b(a, b, median_data);
	while (stack_len(a) > 3)
		pb(a, b);
	sort_three(a);
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

void	sort_100(t_stack **a, t_stack **b)
{
	t_node	*cheapest;
	int		size;

	size = 0;
	if (stack_len(a) <= 100)
	{
		while (stack_len(a) > 3)
			pb(a, b);
		sort_three(a);
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
}

void	sort_stack(t_stack **a, t_stack **b)
{
	if (stack_len(a) <= 100)
		sort_100(a, b);
	else
		sort_500(a, b);
}
