/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:06:24 by istili            #+#    #+#             */
/*   Updated: 2024/05/24 17:44:52 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANDATORY_H
# define MANDATORY_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

void	helper(int ac, char **av, char **arr);
void	main_helper(t_stack **a, t_stack **b, char **split_args);
t_stack	*stack_init(t_stack *a, char **argv);
int		sorted(t_stack **stack);
int		stack_len(t_stack **stack);
void	remove_first(t_stack **stack);
void	add_last(t_stack *stack, int val);
void	add_bigging(t_stack **stack, int val);
t_node	*find_head(t_node *head);
int		is_full_space(char *str);
void	free_array(char **arr);
int		args(char *s);
int		check_double(t_stack **stack);

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

int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
void	*ft_free(char **str, int i);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char *line, char *bufr);
void	ft_puterror(void);

#endif