/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:56:05 by rogde-so          #+#    #+#             */
/*   Updated: 2025/05/09 20:51:03 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	ft_parser(const char *spec, int i, va_list args, int *count)
{
	if (spec[i] == 'c')
		parse_char(spec, i, args, count);
	else if (spec[i] == 's')
		parse_str(args, count);
	else if (spec[i] == '%')
		parse_char(spec, i, args, count);
	else if (spec[i] == 'd' || spec[i] == 'i')
		parse_nbr(args, count);
	else if (spec[i] == 'u')
		parse_unsigned(args, count);
	else if (spec[i] == 'x')
		parse_hex_lower(args, count);
	else if (spec[i] == 'X')
		parse_hex_upper(args, count);
	else if (spec[i] == 'p')
		parse_pointer(args, count);
	else
	{
		write(1, "%", 1);
		write(1, &spec[i], 1);
		(*count) += 2;
	}
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	if (!format || format[ft_strlen(format) - 1] == '%')
		return (-1);
	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			ft_parser(format, i, args, &count);
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
