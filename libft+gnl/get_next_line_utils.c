/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 21:08:54 by rogde-so          #+#    #+#             */
/*   Updated: 2025/06/26 21:11:43 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*gnl_strchr(char *ptr, int c)
{
	if (!ptr)
		return (NULL);
	while (*ptr)
	{
		if ((unsigned char)*ptr == (unsigned char)c)
			return (ptr);
		ptr++;
	}
	return (NULL);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	char	*string;
	char	*ptr;

	i = 0;
	if (!s2)
		return (NULL);
	len1 = gnl_strlen(s1);
	len2 = gnl_strlen(s2);
	string = malloc(len1 + len2 + 1);
	if (!string)
		return (free(s1), NULL);
	ptr = string;
	if (s1)
	{
		while (s1[i])
			*ptr++ = s1[i++];
	}
	while (*s2)
		*ptr++ = *s2++;
	*ptr = '\0';
	free(s1);
	return (string);
}

char	*extract_line(char *s)
{
	size_t	end;
	size_t	i;
	char	*str;

	end = 0;
	i = 0;
	if (!s)
		return (free(s), NULL);
	while (s[end] && s[end] != '\n')
		end++;
	if (s[end] == '\n')
		end++;
	if (end == 0)
		return (free(s), NULL);
	str = malloc(end + 1);
	if (!str)
		return (NULL);
	while (i < end)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*update_ptrbuffer(char *s, size_t start, size_t len)
{
	size_t	i;
	char	*newbuffer;

	i = 0;
	if (!s)
		return (NULL);
	while (s[start] && s[start] != '\n')
		start++;
	if (!s[start])
		return (free(s), NULL);
	start++;
	len = gnl_strlen(s + start);
	if (len == 0)
		return (free(s), NULL);
	newbuffer = malloc(len + 1);
	if (!newbuffer)
		return (free(s), NULL);
	while (i < len)
	{
		newbuffer[i] = s[start + i];
		i++;
	}
	newbuffer[i] = '\0';
	free(s);
	return (newbuffer);
}
