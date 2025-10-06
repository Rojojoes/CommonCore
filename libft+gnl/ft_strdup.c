/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 12:48:08 by rogde-so          #+#    #+#             */
/*   Updated: 2025/04/22 17:38:09 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_length(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	int		l;
	int		i;

	i = 0;
	l = get_length((char *)s);
	ptr = malloc((l + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
/* int	main(int ac, char *av[])
{
	(void)av;
	if (ac == 2)
	{
		printf("%p\n", strdup(NULL));
		//printf("%p", ft_strdup(NULL));
	}
	return (0);
} */
