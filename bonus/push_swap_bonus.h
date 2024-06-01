/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:47:44 by istili            #+#    #+#             */
/*   Updated: 2024/05/24 17:44:01 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "get_next_line/get_next_line.h"

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prv;
	int				data;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
}	t_stack;

void		main_checks(char **split_args);
void		main_helper(t_stack **a, t_stack **b, char **split_args);
void		helper(int ac, char **av, char **split_args, char **arr);
void		*ft_free(char **str, int i);
int			check_double(t_stack **stack);
int			is_full_space(char *s);
int			args(char *s);
void		free_arr(char **arr);
int			ft_isdigit(int c);

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		*ft_strjoin(char *line, char *bufr);
int			ft_strlen(const char *s);
int			ft_atoi(char *str);
char		**ft_split(char const *s, char c);

void		*ft_fre(char **str, int i);
void		ft_puterror(void);
void		freee(t_stack *stack);
void		stack(t_stack **b);
int			stack_len(t_stack **stack);
int			sorted(t_stack **a);
t_stack		*stack_init(t_stack *a, char **av);
void		ft_cmp(t_stack **a, t_stack **b, char *line);

void		sa(t_stack **a);
void		sb(t_stack **b);
void		ss(t_stack **a, t_stack **b);
void		rb(t_stack **b);
void		ra(t_stack **a);
void		rr(t_stack **a, t_stack **b);
void		rra(t_stack **a);
void		rrb(t_stack **b);
void		rrr(t_stack **a, t_stack **b);
void		pa(t_stack **a, t_stack **b);
void		pb(t_stack **a, t_stack **b);

#endif