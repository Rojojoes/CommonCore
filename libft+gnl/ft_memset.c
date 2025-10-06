/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:38:21 by rogde-so          #+#    #+#             */
/*   Updated: 2025/04/22 15:11:03 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t n)
{
	unsigned char	*set;
	unsigned char	value;
	size_t			i;

	set = ptr;
	value = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		set[i] = value;
		i++;
	}
	ptr = (void *)set;
	return (ptr);
}
/* int	main(void)
{
	memset(NULL, 'a', 3);
	ft_memset(NULL, 'a', 3);
} */