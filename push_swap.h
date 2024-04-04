/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 22:05:19 by istili            #+#    #+#             */
/*   Updated: 2024/04/04 01:46:58 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H	
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prv;
	int				data;
	int				target;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
}	t_stack;

t_stack	*stack_init(t_stack *a, char **argv);
int		sorted(t_stack **stack);
int		stack_len(t_stack **stack);
void	print_stack(t_stack **stack);

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

void	remove_first(t_stack **stack);
void	add_last(t_stack *stack, int val);
void	add_bigging(t_stack **stack, int val);
t_node	*find_head(t_node *head);

void	easy(t_stack **a);
t_node	easy2(t_stack **a);
void	sort_for(t_stack **a, t_stack **b);
void	sort_fiv(t_stack **a, t_stack **b);
void	sort_stack(t_stack **a, t_stack **b);
void	freee(t_stack *stack);
void	stack(t_stack **b);
void	check(t_stack **stack);
// int		args(char *s);

int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
void	*ft_free(char **str, int i);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char *line, char *bufr);

void	current_index(t_stack *stack);
void	set_target_a(t_stack **a, t_stack **b);
void	cost_analysis_a(t_stack **a, t_stack **b);
void	set_cheapest(t_stack *stack);
void	set_target_b(t_stack **a, t_stack **b);
void	min_on_top(t_stack **stack);

#endif
