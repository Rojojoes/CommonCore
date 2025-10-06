/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:50:15 by rogde-so          #+#    #+#             */
/*   Updated: 2025/04/22 17:26:05 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	countlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	length_dest;
	size_t	length_src;

	i = 0;
	length_src = countlen((char *)src);
	if (size == 0)
		return (length_src);
	length_dest = countlen(dest);
	if (size <= length_dest)
		return (size + length_src);
	while (i < size - length_dest - 1 && src[i])
	{
		dest[length_dest + i] = src[i];
		i++;
	}
	dest[length_dest + i] = '\0';
	return (length_dest + length_src);
}
/* int	main(int ac, char *av[]void)
{
 	if (ac == 4)
	{
		printf("%zu\n", ft_strlcat(av[1], av[2], atoi(av[3])));
	} 
	char dest[15] = "rrrrrr";
	printf("%zu", ft_strlcat(dest, "lorem ipsum dolor sit amet", 15));
	return (0);
} */
