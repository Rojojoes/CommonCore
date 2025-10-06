/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:55:18 by rogde-so          #+#    #+#             */
/*   Updated: 2025/04/20 12:17:50 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*lastchr;

	lastchr = NULL;
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			lastchr = s;
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return ((char *)lastchr);
}
/*int	main(int ac, char *av[])
{
	if (ac == 3)
	{
		printf("%p\n", ft_strrchr(av[1], atoi(av[2])));
		printf("%p", strrchr(av[1], atoi(av[2])));
	}
	return (0);
}*/
/*char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = NULL;
	while (*s)
	{
		s++;
		i++;
	}
	if (c == '\0')
		return ((char *)s);
	while (i > 0 && s--)
	{
		if (*s == (char)c)
		{
			ptr = (char *)s;
			break ;
		}
		i--;
	}
	return (ptr);
}*/
