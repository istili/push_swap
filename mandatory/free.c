/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:57:52 by istili            #+#    #+#             */
/*   Updated: 2024/05/24 16:42:18 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "mandatory.h"

void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	freee(t_stack *stack)
{
	t_node	*head;
	t_node	*tail;

	head = stack->head;
	tail = stack->tail;
	if (head != NULL)
	{
		while (head->next != NULL)
		{
			head = head->next;
			free(head->prv);
		}
	}
	free(head);
	head = NULL;
	tail = NULL;
	free(stack);
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
