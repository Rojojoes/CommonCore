/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:37:19 by rogde-so          #+#    #+#             */
/*   Updated: 2025/04/21 19:07:01 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (dest == NULL && src == NULL)
		return (dest);
	while (n--)
	{
		*d = *s;
		d++;
		s++;
	}
	return (dest);
}
/* int	main(int ac, char *av[])
{
	if (ac == 4)
	{
		printf("%s", (char *)ft_memcpy(av[1], av[2], atoi(av[3])));
	}
	//char *lol;
	//lol = ft_memcpy(0,0,3);
	return (0);	
} */
