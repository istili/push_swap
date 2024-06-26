/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 05:09:34 by istili            #+#    #+#             */
/*   Updated: 2024/04/27 18:03:27 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "mandatory.h"

void	sa(t_stack **a)
{
	int		i;
	t_node	*node;

	i = 0;
	node = (*a)->head;
	if (node == NULL || node->next == NULL)
		return ;
	i = node->data;
	node->data = node->next->data;
	node->next->data = i;
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	int		i;
	t_node	*node;

	i = 0;
	node = (*b)->head;
	if (node == NULL || node->next == NULL)
		return ;
	i = node->data;
	node->data = node->next->data;
	node->next->data = i;
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}
