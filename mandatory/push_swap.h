/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 22:05:19 by istili            #+#    #+#             */
/*   Updated: 2024/04/27 18:15:46 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H	
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

enum	e_move
{
	RARB,
	RR,
	RRR,
};

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prv;
	int				data;
	int				count;
	enum e_move		act;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
}	t_stack;

void	easy(t_stack **a);
void	sort_for(t_stack **a, t_stack **b);
void	sort_fiv(t_stack **a, t_stack **b);
void	sort_stack(t_stack **a, t_stack **b);
void	freee(t_stack *stack);
void	stack(t_stack **b);

t_node	*find_max(t_stack *stack);
t_node	*find_min(t_stack *stack);
int		ft_index(t_node *head, t_node *node);
int		find_smal(t_stack **stack);

void	count_act(t_stack **a, t_stack **b);
int		find_target(t_stack **b, int data);
void	do_rr(t_stack **a, t_stack **b, t_node *cheapest);
void	do_rrr(t_stack **a, t_stack **b, t_node *cheapest);
void	do_rarb(t_stack **a, t_stack **b, t_node *cheapest);

void	count_act_a(t_stack **a, t_stack **b);
int		find_target_a(t_stack **a, int data);
void	do_rrr_a(t_stack **a, t_stack**b, t_node*cheapest);
void	do_rr_a(t_stack **a, t_stack**b, t_node*cheapest);
void	do_rarb_a(t_stack **a, t_stack**b, t_node*cheapest);

int		get_medain(t_stack **stack);
void	push_to_b(t_stack **a, t_stack **b, int medain);
void	sort_500(t_stack **a, t_stack **b);
t_node	*find_cheapest(t_stack **a);
void	push_cheapest_a(t_stack **a, t_stack **b, t_node *cheapest);

#endif