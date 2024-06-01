/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:24:53 by istili            #+#    #+#             */
/*   Updated: 2024/05/23 19:34:11 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa(t_stack **a)
{
	int		i;
	t_node	*node;

	if (stack_len(a) < 2)
		return ;
	i = 0;
	node = (*a)->head;
	if (node == NULL || node->next == NULL)
		return ;
	i = node->data;
	node->data = node->next->data;
	node->next->data = i;
}

void	sb(t_stack **b)
{
	int		i;
	t_node	*node;

	if (stack_len(b) < 2)
		return ;
	i = 0;
	node = (*b)->head;
	if (node == NULL || node->next == NULL)
		return ;
	i = node->data;
	node->data = node->next->data;
	node->next->data = i;
}

void	ss(t_stack **a, t_stack **b)
{
	if (stack_len(a) < 2 && stack_len(b) < 2)
		return ;
	sa(a);
	sb(b);
}
