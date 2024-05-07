/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:59:08 by istili            #+#    #+#             */
/*   Updated: 2024/05/07 19:37:37 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "mandatory.h"

int	find_target_a(t_stack **a, int data)
{
	t_node	*head;
	t_node	*tail;

	head = (*a)->head;
	tail = (*a)->tail;
	if (data > find_max(*a)->data || data < find_min(*a)->data)
		return (ft_index((*a)->head, find_min(*a)));
	if (data < head->data && data > tail->data)
		return (0);
	while (head->next)
	{
		if (data > head->data && data < head->next->data)
			return (ft_index((*a)->head, head->next));
		head = head->next;
	}
	return (0);
}

int	find_small(t_stack **stack)
{
	t_node	*head;
	int		min;

	head = (*stack)->head;
	min = (*stack)->head->data;
	while (head)
	{
		if (min > head->data)
			min = head->data;
		head = head->next;
	}
	return (min);
}

void	sort_500(t_stack **a, t_stack **b)
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
