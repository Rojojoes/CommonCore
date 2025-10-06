/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:23:29 by rogde-so          #+#    #+#             */
/*   Updated: 2025/05/07 21:03:02 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	parse_char(const char *spec, int i, va_list args, int *count)
{
	int	ch;

	if (spec[i] == 'c')
	{
		ch = va_arg(args, int);
		write(1, &ch, 1);
		(*count)++;
		return ;
	}
	else if (spec[i] == '%')
	{
		write(1, "%", 1);
		(*count)++;
		return ;
	}
}

void	parse_str(va_list args, int *count)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
	{
		write(1, "(null)", 6);
		(*count) += 6;
		return ;
	}
	write(1, str, ft_strlen(str));
	(*count) += ft_strlen(str);
	return ;
}

void	parse_nbr(va_list args, int *count)
{
	int		nb;
	char	*str;

	nb = va_arg(args, int);
	str = ft_itoa(nb);
	if (str)
	{
		write(1, str, ft_strlen(str));
		(*count) += ft_strlen(str);
		free(str);
	}
}

void	parse_unsigned(va_list args, int *count)
{
	unsigned int	nb;
	char			c[11];
	int				len;

	len = 0;
	nb = va_arg(args, unsigned int);
	if (nb == 0)
	{
		write(1, "0", 1);
		(*count)++;
		return ;
	}
	while (nb > 0)
	{
		c[len++] = (nb % 10) + '0';
		nb /= 10;
	}
	(*count) += len;
	while (--len >= 0)
		write(1, &c[len], 1);
	return ;
}
