/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 20:24:11 by rogde-so          #+#    #+#             */
/*   Updated: 2025/04/20 11:18:16 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_swap(char *ptr, int i)
{
	int		start;
	char	temp;

	start = 0;
	while (start < i)
	{
		temp = ptr[start];
		ptr[start] = ptr[i];
		ptr[i] = temp;
		start++;
		i--;
	}
}

static char	*case_checks(int n)
{
	char	*ptr;

	if (n == -2147483648)
	{
		ptr = ft_strdup("-2147483648");
		return (ptr);
	}
	if (n == 0)
	{
		ptr = ft_strdup("0");
		return (ptr);
	}
	return (ptr = NULL);
}

static size_t	get_length(int n)
{
	size_t	len;

	len = 0;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_transform(char *result, int negative, int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		result[i] = n % 10 + '0';
		n /= 10;
		i++;
	}
	if (negative > 0)
		result[i++] = '-';
	ft_swap(result, i - 1);
	result[i] = '\0';
	return (result);
}

char	*ft_itoa(int n)
{
	char			*result;
	int				is_negative;
	size_t			len;

	is_negative = 0;
	if (n == -2147483648 || n == 0)
		return (case_checks(n));
	if (n < 0)
	{
		n = -n;
		len = get_length(n) + 1;
		is_negative++;
	}
	else
		len = get_length(n);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	return (ft_transform(result, is_negative, n));
}
/*int	main(int ac, char *av[])
{
	if (ac == 2)
	{
		printf("%s", ft_itoa(atoi(av[1])));
	}
	return (0);
}*/
