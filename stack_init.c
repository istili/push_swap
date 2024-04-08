/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 22:25:15 by istili            #+#    #+#             */
/*   Updated: 2024/04/08 03:51:11 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*find_last(t_stack *stack)
{
	t_node	*head;

	head = stack->head;
	if (!head)
		return (0);
	while (head->next)
		head = head->next;
	return (head);
}

static void	add_node(t_stack *stack, int nbr)
{
	t_node		*node;
	t_node		*last_node;

	if (NULL == stack)
		return ;
	node = malloc(sizeof(t_node));
	if (!node)
		return ;
	node->next = NULL;
	node->data = nbr;
	node->act = -1;
	node->count = -1;
	last_node = find_last(stack);
	last_node->next = node;
	node->prv = last_node;
	stack->tail = node;
}

void	add_bigging(t_stack **stack, int val)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->data = val;
	new_node->prv = NULL;
	new_node->next = NULL;
	new_node->act = -1;
	new_node->count = -1;
	new_node->next = (*stack)->head;
	if ((*stack)->head)
		(*stack)->head->prv = new_node;
	else
		(*stack)->tail = new_node;
	(*stack)->head = new_node;
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

t_stack	*stack_init(t_stack *a, char **argv)
{
	long	nbr;
	int		i;

	i = 0;
	a = malloc(sizeof(t_stack));
	if (!a)
		return (NULL);
	a->head = malloc(sizeof(t_node));
	a->head->next = NULL;
	a->head->prv = NULL;
	a->head->data = ft_atoi(argv[i++]);
	a->head->count = -1;
	a->head->act = -1;
	a->tail = a->head;
	while (argv[i])
	{
		nbr = ft_atoi(argv[i]);
		add_node(a, nbr);
		i++;
	}
	ft_free(argv, i);
	return (a);
}
