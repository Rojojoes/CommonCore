/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 18:28:43 by rogde-so          #+#    #+#             */
/*   Updated: 2025/10/06 03:04:42 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicates(t_node *a)
{
	t_node	*i;
	t_node	*j;

	i = a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->number == j->number)
				return (1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}

int	parse_leading(const char **ptr, int *sign)
{
	const char	*p;

	p = *ptr;
	while (*p && ft_isspace((unsigned char)*p))
		p++;
	*sign = 1;
	if (*p == '+' || *p == '-')
	{
		if (*p == '-')
			*sign = -1;
		p++;
	}
	if (!(*p >= '0' && *p <= '9'))
		return (1);
	*ptr = p;
	return (0);
}

int	parse_token(const char **str, int *value)
{
	long long	result;
	int			sign;
	const char	*ptr;
	int			digit;

	result = 0;
	ptr = *str;
	if (parse_leading(&ptr, &sign))
		return (1);
	if (!(ptr && *ptr >= '0' && *ptr <= '9'))
		return (1);
	while (*ptr >= '0' && *ptr <= '9')
	{
		digit = *ptr - '0';
		result = result * 10 + digit;
		if ((sign == 1 && result > INT_MAX)
			|| (sign == -1 && result > (long long)INT_MAX + 1))
			return (1);
		ptr++;
	}
	if (*ptr != '\0' && !ft_isspace((unsigned char)*ptr))
		return (1);
	*value = (int)(result * sign);
	*str = ptr;
	return (0);
}

int	populate_stack(const char *str, t_node **a)
{
	int		value;
	t_node	*node;

	while (*str)
	{
		while (*str && ft_isspace((unsigned char)*str))
			str++;
		if (*str == '\0')
			break ;
		if (parse_token(&str, &value))
			return (1);
		node = new_node(value);
		if (!node)
			return (1);
		append_node(a, node);
	}
	return (0);
}

int	process_arg(int ac, char *av[], t_node **a, int index)
{
	const char	*str;
	const char	*ptr;

	while (index < ac)
	{
		str = av[index];
		ptr = str;
		while (*ptr && ft_isspace((unsigned char)*ptr))
			ptr++;
		if (*ptr == '\0')
			return (free_list(a), 1);
		if (populate_stack(str, a) != 0)
			return (free_list(a), 1);
		index++;
	}
	return (0);
}
