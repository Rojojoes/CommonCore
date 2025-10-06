/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:48:55 by rogde-so          #+#    #+#             */
/*   Updated: 2025/10/06 06:39:52 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct stack_list
{
	int					number;
	long				index;
	struct stack_list	*next;
}	t_node;

/// Helper Functions ///
int		ft_isspace(unsigned char c);
int		stack_size(t_node *stack);
int		is_sorted(t_node *a);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);
/// Movement Functions ///
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);
/// List Functions ///
void	free_list(t_node **lst);
void	append_node(t_node **lst, t_node *new);
int		populate_stack(const char *str, t_node **a);
t_node	*new_node(int content);
/// Arg Parse Functions ///
int		process_arg(int ac, char *av[], t_node **a, int index);
int		check_duplicates(t_node *a);
int		parse_leading(const char **ps, int *sign);
int		parse_token(const char **s, int *out);
/// Algorithm Functions ///
void	push_swap(t_node **a, t_node **b, int size);
void	micro_sort(t_node **stack);
void	tiny_sort(t_node **a, t_node **b, int size);
void	big_sort(t_node **a, t_node **b, int size, int i);

#endif