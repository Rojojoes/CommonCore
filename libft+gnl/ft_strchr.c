/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:38:15 by rogde-so          #+#    #+#             */
/*   Updated: 2025/04/22 17:41:47 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	while (*ptr)
	{
		if ((unsigned char)*ptr == (unsigned char)c)
			return (ptr);
		ptr++;
	}
	if ((unsigned char)c == '\0')
		return (ptr);
	return (NULL);
}
/* int	main(int ac, char *av[])
{
	if (ac == 3)
	{
		printf("%s\n", ft_strchr(av[1], atoi(av[2])));
		printf("%s", strchr(av[1], atoi(av[2])));
	}
	return (0);
} */
