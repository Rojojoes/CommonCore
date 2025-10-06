/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 02:26:23 by rogde-so          #+#    #+#             */
/*   Updated: 2025/10/06 09:15:29 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	indexer(t_node **stack, int size)
{
	int		index;
	t_node	*ptr;
	t_node	*smallest;

	index = 0;
	while (index < size)
	{
		ptr = *stack;
		smallest = NULL;
		while (ptr)
		{
			if (ptr->index == -1)
				if (!smallest || ptr->number < smallest->number)
					smallest = ptr;
			ptr = ptr->next;
		}
		smallest->index = index;
		index++;
	}
}

void	big_sort(t_node **a, t_node **b, int size, int i)
{
	long	number;
	int		max_bits;
	int		j;

	max_bits = 0;
	indexer(a, size);
	while (((size - 1) >> max_bits) != 0)
		max_bits++;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			number = (*a)->index;
			if (((number >> i) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			j++;
		}
		while (*b)
			pa(a, b);
		i++;
	}
}

static int	find_smallest_index(t_node *stack)
{
	int		index;
	int		min_index;
	int		min_value;
	t_node	*node;

	index = 0;
	min_index = 0;
	node = stack;
	min_value = node->number;
	while (node)
	{
		if (node->number < min_value)
		{
			min_value = node->number;
			min_index = index;
		}
		node = node->next;
		index++;
	}
	return (min_index);
}

void	tiny_sort(t_node **a, t_node **b, int size)
{
	int	smallest;
	int	loop;

	loop = 2;
	while (loop--)
	{
		size = stack_size(*a);
		smallest = find_smallest_index(*a);
		if (smallest <= size / 2)
			while (smallest--)
				ra(a);
		else
			while (size - smallest++)
				rra(a);
		pb(a, b);
	}
	micro_sort(a);
	if (is_sorted(*b) == 0)
		sb(b);
	pa(a, b);
	pa(a, b);
}

void	micro_sort(t_node **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->number;
	b = (*stack)->next->number;
	c = (*stack)->next->next->number;
	if (a > b && b > c && c < a)
		return (sa(stack), rra(stack));
	if (a < b && b > c && c > a)
		return (sa(stack), ra(stack));
	if (a > b && b < c && c < a)
		return (ra(stack));
	if (a > b && b < c && c > a)
		return (sa(stack));
	if (a < b && b > c && c < a)
		return (rra(stack));
	return ;
}
