/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:31:23 by rogde-so          #+#    #+#             */
/*   Updated: 2025/04/22 15:02:57 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*dest;
	const unsigned char	*src;
	size_t				i;

	dest = (const unsigned char *)s1;
	src = (const unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n && dest[i] == src[i])
		i++;
	if (i == n)
		return (0);
	return (dest[i] - src[i]);
}
/* int	main(int ac, char *av[]void)
{
	if (ac == 4)
	{
		printf("%d\n", ft_memcmp(av[1], av[2], atoi(av[3])));
		printf("%d", memcmp(av[1], av[2], atoi(av[3])));
	}
	return (0);
} */
