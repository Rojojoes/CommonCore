/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 11:58:04 by rogde-so          #+#    #+#             */
/*   Updated: 2025/04/21 14:42:06 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*ptr;
	char		*zeroptr;
	size_t		i;

	i = 0;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (!(nmemb > SIZE_MAX / size))
		ptr = malloc(nmemb * size);
	else
		return (0);
	if (ptr == NULL)
		return (NULL);
	zeroptr = ptr;
	while (i < nmemb * size)
		zeroptr[i++] = 0;
	return (ptr);
}
/* int	main(int ac, char *av[])
{
	char *lol1;

	lol1 = ft_calloc(12, 11);
	free(lol1);
	return (0);
} */
