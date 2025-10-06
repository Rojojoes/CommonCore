/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:17:03 by rogde-so          #+#    #+#             */
/*   Updated: 2025/04/22 15:28:24 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_length(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		start;
	int		end;
	int		i;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[start] && check_set(s1[start], set))
		start++;
	end = ft_length(s1) - 1;
	while (end > start && check_set(s1[end], set))
		end--;
	ptr = malloc(1 + (end - start + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (start <= end)
	{
		ptr[i++] = s1[start++];
	}
	ptr[i] = '\0';
	return (ptr);
}
/*int	main(int ac, char *av[])
{
	if (ac == 3)
	{
		printf("%s", ft_strtrim(av[1], av[2]));
	}
	return (0);
}*/
