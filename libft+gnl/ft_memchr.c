/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:17:13 by rogde-so          #+#    #+#             */
/*   Updated: 2025/04/22 15:19:39 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	size_t				i;

	ptr = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return ((void *)(ptr + i));
		i++;
	}
	return (NULL);
}
/* int	main(int ac, char *av[])
{
	if (ac == 4)
	{
		printf("%p\n", ft_memchr(av[1], av[2][0], atoi(av[3])));
		printf("%p", memchr(av[1], av[2][0], atoi(av[3])));
	}
	return (0);
} */
