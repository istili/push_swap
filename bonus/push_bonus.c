/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:54:08 by istili            #+#    #+#             */
/*   Updated: 2024/05/23 18:20:25 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	add_bigging(t_stack **stack, int val)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		ft_puterror();
	new_node->data = val;
	new_node->prv = NULL;
	new_node->next = NULL;
	new_node->next = (*stack)->head;
	if ((*stack)->head)
		(*stack)->head->prv = new_node;
	else
		(*stack)->tail = new_node;
	(*stack)->head = new_node;
}

static void	remove_first(t_stack **stack)
{
	t_node	*ptr;

	if ((*stack)->head != NULL)
	{
		ptr = (*stack)->head;
		(*stack)->head = (*stack)->head->next;
		free(ptr);
		if ((*stack)->head)
			(*stack)->head->prv = NULL;
	}
}

void	pa(t_stack **a, t_stack **b)
{
	int		i;

	if (stack_len(b) == 0)
		return ;
	i = (*b)->head->data;
	remove_first(b);
	add_bigging(a, i);
}

void	pb(t_stack **a, t_stack **b)
{
	int		i;

	if (stack_len(a) == 0)
		return ;
	i = (*a)->head->data;
	remove_first(a);
	add_bigging(b, i);
}
