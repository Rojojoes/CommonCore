/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:54:12 by rogde-so          #+#    #+#             */
/*   Updated: 2025/04/23 12:52:21 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t				i;
	size_t				l;

	if (little[0] == '\0')
		return ((char *)big);
	if (len > ft_strlen(big))
		len = ft_strlen(big);
	if (big[0] == '\0')
		return (NULL);
	i = 0;
	while (i < len)
	{
		l = 0;
		if (big[i] == little[l])
		{
			while (little[l] && i + l < len && big[i + l] == little[l])
				l++;
			if (little[l] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
/*int	main(int ac, char *av[])
{
	if (ac == 4)
	{
		printf("%s", ft_strnstr(av[1], av[2], atoi(av[3])));
	}
	return (0);
}*/
