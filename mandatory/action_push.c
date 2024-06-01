/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 01:37:30 by istili            #+#    #+#             */
/*   Updated: 2024/05/23 18:21:35 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "mandatory.h"

void	pa(t_stack **a, t_stack **b)
{
	int		i;

	i = (*b)->head->data;
	remove_first(b);
	add_bigging(a, i);
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	int		i;

	i = (*a)->head->data;
	remove_first(a);
	add_bigging(b, i);
	write(1, "pb\n", 3);
}
