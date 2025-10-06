/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils_hexa.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:28:30 by rogde-so          #+#    #+#             */
/*   Updated: 2025/05/07 21:03:02 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	parse_hex_lower(va_list args, int *count)
{
	char			*hex;
	char			array[11];
	unsigned int	index;
	unsigned int	nb;

	index = 0;
	hex = "0123456789abcdef";
	nb = va_arg(args, unsigned int);
	if (nb == 0)
	{
		write(1, "0", 1);
		(*count)++;
		return ;
	}
	while (nb > 0)
	{
		array[index++] = hex[nb % 16];
		nb /= 16;
	}
	while (index-- > 0)
	{
		write(1, &array[index], 1);
		(*count)++;
	}
}

void	parse_hex_upper(va_list args, int *count)
{
	char			*hex;
	char			array[11];
	unsigned int	index;
	unsigned int	nb;

	index = 0;
	hex = "0123456789ABCDEF";
	nb = va_arg(args, unsigned int);
	if (nb == 0)
	{
		write(1, "0", 1);
		(*count)++;
		return ;
	}
	while (nb > 0)
	{
		array[index++] = hex[nb % 16];
		nb /= 16;
	}
	while (index-- > 0)
	{
		write(1, &array[index], 1);
		(*count)++;
	}
}

void	parse_pointer(va_list args, int *count)
{
	char			array[18];
	unsigned int	index;
	uintptr_t		address;

	address = (uintptr_t)va_arg(args, void *);
	if (address == 0)
	{
		write(1, "(nil)", 5);
		(*count) += 5;
		return ;
	}
	index = 0;
	while (address > 0)
	{
		array[index++] = "0123456789abcdef"[address % 16];
		address /= 16;
	}
	write(1, "0x", 2);
	(*count) += 2;
	while (index-- > 0)
	{
		write(1, &array[index], 1);
		(*count)++;
	}
}
