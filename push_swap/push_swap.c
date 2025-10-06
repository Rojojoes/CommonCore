/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:12:48 by rogde-so          #+#    #+#             */
/*   Updated: 2025/10/06 09:15:05 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_node **a, t_node **b, int size)
{
	if (size == 2)
		sa(a);
	else if (size == 3)
		micro_sort(a);
	else if (size == 5)
		tiny_sort(a, b, size);
	else
		big_sort(a, b, size, 0);
}

int	main(int ac, char *av[])
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (1);
	if (process_arg(ac, av, &a, 1) != 0)
		return (free_list(&a), ft_putstr_fd("Error\n", 2), 1);
	if (check_duplicates(a) != 0)
		return (free_list(&a), ft_putstr_fd("Error\n", 2), 1);
	if (is_sorted(a) == 0)
		return (free_list(&a), 0);
	push_swap(&a, &b, stack_size(a));
	free_list(&a);
	return (0);
}
