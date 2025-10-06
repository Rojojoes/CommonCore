/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfmain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 19:41:20 by rogde-so          #+#    #+#             */
/*   Updated: 2025/05/09 20:51:18 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int		i;
	int		f;
	char	*null_str;
	void	*non_null_ptr;

	i = 0;
	f = 0;
	null_str = NULL;
	non_null_ptr = (void *)0x1234abcd;
	f += ft_printf("FT_PRINT: %s\n", "OH MANINHO PRINT");
	f += ft_printf("FT_PRINT: %c.%c,%c/%c\n", 'c', 'r', 'l', 'h');
	f += ft_printf("FT_PRINT: %i, %d\n", f, 69);
	f += ft_printf("FT_PRINT: %u\n", -69);
	f += ft_printf("FT_PRINT: %x && %X\n", 1995, 1996);
	f += ft_printf("FT_PRINT: %p\n", null_str);
	f += ft_printf("FT_PRINT: NULL str -> %s\n", null_str);
	f += ft_printf("FT_PRINT: INT_MIN -> %d\n", INT_MIN);
	f += ft_printf("FT_PRINT: INT_MAX -> %d\n", INT_MAX);
	f += ft_printf("FT_PRINT: 0 as int/hex/u -> %d, %x, %u\n", 0, 0, 0);
	f += ft_printf("FT_PRINT: percent -> %%\n");
	f += ft_printf("FT_PRINT: non-null ptr: %p\n", non_null_ptr);
	f += ft_printf("FT_PRINT: mixed -> %d and %s and %x!\n", 42, "hello", 255);
	f += ft_printf("FT_PRINT: wrong spec -> %r\n");
	f += ft_printf("FT_PRINT:%%");
	ft_printf("ft_print_%d\n", f);
}

/* int	main(void)
{
	int		i;
	int		p;
	char	*null_str;
	void	*non_null_ptr;

	i = 0;
	p = 0;
	null_str = NULL;
	non_null_ptr = (void *)0x1234abcd;
	p += printf("__PRINT_: %s\n", "OH MANINHO PRINT");
	p += printf("__PRINT_: %c.%c,%c/%c\n", 'c', 'r', 'l', 'h');
	p += printf("__PRINT_: %i, %d\n", p, 69);
	p += printf("__PRINT_: %u\n", -69);
	p += printf("__PRINT_: %x && %X\n", 1995, 1996);
	p += printf("__PRINT_: %p\n", null_str);
	p += printf("__PRINT_: NULL str -> %s\n", null_str);
	p += printf("__PRINT_: INT_MIN -> %d\n", INT_MIN);
	p += printf("__PRINT_: INT_MAX -> %d\n", INT_MAX);
	p += printf("__PRINT_: 0 as int/hex/u -> %d, %x, %u\n", 0, 0, 0);
	p += printf("__PRINT_: percent -> %%\n");
	p += printf("__PRINT_: non-null ptr: %p\n", non_null_ptr);
	p += printf("__PRINT_: mixed -> %d and %s and %x!\n", 42, "hello", 255);
	//p += printf("__PRINT_: wrong spec -> %r\n");
	//p += printf("__PRINT_:%");
	printf("print_%d\n", p);
} */