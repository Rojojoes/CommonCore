/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:53:41 by rogde-so          #+#    #+#             */
/*   Updated: 2025/05/07 20:55:32 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <limits.h>
# include "libft/libft.h"

int		ft_printf(const char *format, ...);
void	ft_parser(const char *spec, int i, va_list args, int *count);
void	parse_char(const char *spec, int i, va_list args, int *count);
void	parse_str(va_list args, int *count);
void	parse_nbr(va_list args, int *count);
void	parse_unsigned(va_list args, int *count);
void	parse_hex_lower(va_list args, int *count);
void	parse_hex_upper(va_list args, int *count);
void	parse_pointer(va_list args, int *count);

#endif