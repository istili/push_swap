/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ac_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:02:26 by istili            #+#    #+#             */
/*   Updated: 2024/05/24 17:28:41 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "mandatory.h"

int	check_double(t_stack **stack)
{
	t_node	*i;
	t_node	*j;

	i = (*stack)->head;
	while (i)
	{
		j = (*stack)->head;
		while (j)
		{
			if (i != j && i->data == j->data)
				return (0);
			j = j->next;
		}
		i = i->next;
	}
	return (1);
}

int	args(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!s[i])
		return (0);
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	if (s[i] == '\0')
		return (1);
	return (0);
}

int	is_full_space(char *str)
{
	while (*str == '\t' || *str == ' ')
		str++;
	if (*str != '\0')
		return (0);
	return (1);
}

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

t_node	*find_head(t_node *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}
