/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:56:32 by istili            #+#    #+#             */
/*   Updated: 2024/05/06 14:44:52 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "mandatory.h"

static void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	insertion_sort(int *tab, int size)
{
	int	i;
	int	j;

	i = 1;
	while (i < size)
	{
		j = i;
		while (j > 0 && (tab[j] < tab[j - 1]))
		{
			swap(&tab[j], &tab[j - 1]);
			j = j - 1;
		}
		i++;
	}
}

int	get_medain(t_stack **stack)
{
	int		*tab;
	t_node	*head;
	int		i;
	int		medain;

	i = 0;
	tab = malloc(sizeof(int) * stack_len(stack));
	if (!tab)
		ft_puterror();
	head = (*stack)->head;
	while (head)
	{
		tab[i++] = head->data;
		head = head->next;
	}
	insertion_sort(tab, i);
	medain = tab[i / 2];
	free(tab);
	return (medain);
}

void	make_act(t_stack **a, t_stack **b, int i, int j)
{
	if (i < j)
	{
		while (i--)
			ra(a);
	}
	else
	{
		while (j--)
			rra(a);
	}
	pb(a, b);
}

void	push_to_b(t_stack **a, t_stack **b, int medain)
{
	t_node	*head_a;
	t_node	*tail;
	int		i;
	int		j;

	head_a = (*a)->head;
	tail = (*a)->tail;
	i = 0;
	j = 1;
	while (head_a && head_a->data > medain)
	{
		i++;
		head_a = head_a->next;
	}
	while (tail && tail->data > medain)
	{
		j++;
		tail = tail->prv;
	}
	make_act(a, b, i, j);
}
