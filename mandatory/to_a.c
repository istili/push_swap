/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_a.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:14:51 by istili            #+#    #+#             */
/*   Updated: 2024/05/07 19:38:32 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "mandatory.h"

static int	min(int a, int b)
{
	if (a >= b)
		return (b);
	return (a);
}

static int	max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

static void	checks(int	*nb_steps, t_node *head)
{
	if (nb_steps[RARB] <= nb_steps[RR]
		&& nb_steps[RARB] <= nb_steps[RRR])
	{
		head->count = nb_steps[RARB];
		head->act = RARB;
	}
	else if (nb_steps[RR] <= nb_steps[RARB]
		&& nb_steps[RR] <= nb_steps[RRR])
	{
		head->count = nb_steps[RR];
		head->act = RR;
	}
	else if (nb_steps[RRR] <= nb_steps[RR]
		&& nb_steps[RRR] <= nb_steps[RARB])
	{
		head->count = nb_steps[RRR];
		head->act = RRR;
	}
}

static void	fill_node_b(t_node *head_b, t_stack **a, t_stack **b)
{
	int		indx_b;
	int		aim;
	int		size_a;
	int		size_b;
	int		nb_steps[3];

	size_a = stack_len(a);
	size_b = stack_len(b);
	aim = find_target_a(a, head_b->data);
	indx_b = ft_index((*b)->head, head_b);
	nb_steps[RARB] = min(aim, size_a - aim) + min(indx_b, size_b - indx_b) + 1;
	nb_steps[RR] = max(indx_b, aim) + 1;
	nb_steps[RRR] = max(size_a - aim, size_b - indx_b) + 1;
	checks(nb_steps, head_b);
}

void	count_act_a(t_stack **a, t_stack **b)
{
	t_node	*head_b;

	head_b = (*b)->head;
	while (head_b)
	{
		fill_node_b(head_b, a, b);
		head_b = head_b->next;
	}
}
