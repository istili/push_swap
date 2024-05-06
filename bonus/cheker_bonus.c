/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheker_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:59:21 by istili            #+#    #+#             */
/*   Updated: 2024/04/27 13:53:20 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	stack(t_stack **b)
{
	*b = malloc(sizeof(t_stack));
	if (!b)
		return ;
	(*b)->head = NULL;
	(*b)->tail = NULL;
}

void	freee(t_stack *stack)
{
	t_node	*head;
	t_node	*tail;

	if (!stack)
		return ;
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

static int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1 && s1[i] && s1[i] == s2[i])
		i++;
	return ((int)s1[i] - (int)s2[i]);
}

void	ft_puterror(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_cmp(t_stack **a, t_stack **b, char *line)
{
	if (!ft_strcmp(line, "sa\n"))
		sa(a);
	else if (!ft_strcmp(line, "sb\n"))
		sb(b);
	else if (!ft_strcmp(line, "ss\n"))
		ss(a, b);
	else if (!ft_strcmp(line, "ra\n"))
		ra(a);
	else if (!ft_strcmp(line, "rb\n"))
		rb(b);
	else if (!ft_strcmp(line, "rr\n"))
		rr(a, b);
	else if (!ft_strcmp(line, "rra\n"))
		rra(a);
	else if (!ft_strcmp(line, "rrb\n"))
		rrb(b);
	else if (!ft_strcmp(line, "rrr\n"))
		rrr(a, b);
	else if (!ft_strcmp(line, "pa\n"))
		pa(a, b);
	else if (!ft_strcmp(line, "pb\n"))
		pb(a, b);
	else
		ft_puterror();
}
