/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 22:25:15 by istili            #+#    #+#             */
/*   Updated: 2024/05/24 14:00:48 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "mandatory.h"

void	add_bigging(t_stack **stack, int val)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		ft_puterror();
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

	node = malloc(sizeof(t_node));
	if (!node)
		ft_puterror();
	node->next = NULL;
	node->data = nbr;
	node->act = -1;
	node->count = -1;
	last_node = find_last(stack);
	last_node->next = node;
	node->prv = last_node;
	stack->tail = node;
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
	if (!a->head)
		return (NULL);
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
