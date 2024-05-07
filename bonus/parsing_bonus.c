/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:37:56 by istili            #+#    #+#             */
/*   Updated: 2024/05/07 19:46:15 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_node	*find_last(t_stack *a)
{
	t_node	*head;

	head = a->head;
	if (!head)
		return (0);
	while (head->next)
		head = head->next;
	return (head);
}

int	stack_len(t_stack **stack)
{
	t_node	*head;
	int		i;

	if (stack == NULL || (*stack)->head == NULL)
		return (0);
	head = (*stack)->head;
	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}

int	sorted(t_stack **a)
{
	t_node	*cur;

	cur = (*a)->head;
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

static void	add_node(t_stack *a, int data)
{
	t_node	*node;
	t_node	*last_node;

	node = malloc(sizeof(t_node));
	if (!node)
		return ;
	node->next = NULL;
	node->data = data;
	last_node = find_last(a);
	last_node->next = node;
	node->prv = last_node;
	a->tail = node;
}

t_stack	*stack_init(t_stack *a, char **av)
{
	long	nb;
	int		i;

	i = 0;
	a = malloc(sizeof(t_stack));
	if (!a)
		return (NULL);
	a->head = malloc(sizeof(t_node));
	a->head->next = NULL;
	a->head->prv = NULL;
	a->head->data = ft_atoi(av[i++]);
	a->tail = a->head;
	while (av[i])
	{
		nb = ft_atoi(av[i]);
		add_node(a, nb);
		i++;
	}
	ft_free(av, i);
	return (a);
}
