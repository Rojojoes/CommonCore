/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:34:42 by rogde-so          #+#    #+#             */
/*   Updated: 2025/04/22 19:42:31 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	sub;

	i = 0;
	sub = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			sub++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (sub);
}

static int	ft_length(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

void	*ft_freemem(char **array, int i)
{
	while (--i >= 0)
		free(array[i]);
	return (NULL);
}

static char	**true_split(char const *s, char c, char **array)
{
	int	substring;
	int	i;
	int	j;
	int	len;

	substring = 0;
	j = 0;
	while (s[j])
	{
		while (s[j] == c)
			j++;
		if (s[j])
		{
			len = ft_length(s, c, j);
			array[substring] = malloc(sizeof(char) * (len + 1));
			if (!array[substring])
				return (ft_freemem(array, substring));
			i = 0;
			while (i < len)
				array[substring][i++] = s[j++];
			array[substring++][i] = '\0';
		}
	}
	array[substring] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	if (!s)
		return (NULL);
	array = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (array == NULL)
		return (NULL);
	if (!true_split(s, c, array))
	{
		free(array);
		return (NULL);
	}
	return (array);
}
/* int	main(int ac, char *av[])
{
	//int	i = 0;
	//char	c = av[2][0];
	if (ac == 3)
	{
		char **arr = ft_split(av[1], c);
		while (arr[i] != NULL)
		{
			printf("%s\n", arr[i]);
			i++;
			}
	} 
	ft_split("hello!", ' ');
	return (0);
} */
/* 
int	main(int ac, char *av[])
{
	int i = -1;
	char **lol1;

	lol1 = ft_split("xxxxxxxxhello!", 'x');
	while(lol1[++i])
	{
		printf("%s\n", lol1[i]);
		free(lol1[i]);
	}
	printf("%i\n", i);
	free(lol1);
	return (0);
} */