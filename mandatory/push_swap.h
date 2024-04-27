/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 22:05:19 by istili            #+#    #+#             */
/*   Updated: 2024/04/27 11:51:46 by istili           ###   ########.fr       */
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

// parsing
t_stack	*stack_init(t_stack *a, char **argv);
int		sorted(t_stack **stack);
int		stack_len(t_stack **stack);
void	print_stack(t_stack **stack);
void	remove_first(t_stack **stack);
void	add_last(t_stack *stack, int val);
void	add_bigging(t_stack **stack, int val);
t_node	*find_head(t_node *head);
int		is_full_space(char *str);
void	free_array(char **arr);
int		args(char *s);
int		check_double(t_stack **stack);


// actions
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

// sort
void	easy(t_stack **a);
void	sort_for(t_stack **a, t_stack **b);
void	sort_fiv(t_stack **a, t_stack **b);
void	sort_stack(t_stack **a, t_stack **b);
void	freee(t_stack *stack);
void	stack(t_stack **b);

// libc
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
void	*ft_free(char **str, int i);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char *line, char *bufr);

// utils
t_node	*find_max(t_stack *stack);
t_node	*find_min(t_stack *stack);
int		ft_index(t_node *head, t_node *node);
int		find_smal(t_stack **stack);

// pushing to b
void	count_act(t_stack **a, t_stack **b);
int		find_target(t_stack **b, int data);
void	do_rr(t_stack **a, t_stack **b, t_node *cheapest);
void	do_rrr(t_stack **a, t_stack **b, t_node *cheapest);
void	do_rarb(t_stack **a, t_stack **b, t_node *cheapest);

// pushing to a
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
