/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:11:49 by istili            #+#    #+#             */
/*   Updated: 2024/04/19 13:58:47 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted(t_stack **stack)
{
	t_node	*cur;

	cur = (*stack)->head;
	if (!cur || !cur->next)
		return (1);
	while (cur->next)
	{
		if (cur->data > cur->next->data)
			return (0);
		cur = cur->next;
	}
	return (1);
}

int	stack_len(t_stack **stack)
{
	int		count;
	t_node	*head;

	if ((*stack)->head == NULL)
		return (0);
	head = (*stack)->head;
	count = 0;
	while (head)
	{
		count++;
		head = head->next;
	}
	return (count);
}

void	remove_first(t_stack **stack)
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

t_node	*find_head(t_node *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void	stack(t_stack **b)
{
	*b = malloc(sizeof(t_stack));
	if (!(*b))
		return ;
	(*b)->head = NULL;
	(*b)->tail = NULL;
}
