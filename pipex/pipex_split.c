/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:32:23 by rogde-so          #+#    #+#             */
/*   Updated: 2025/08/30 19:36:40 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	count_strings(char *s, int i, int count)
{
	char	quote;

	while (s[i])
	{
		while (s[i] == ' ')
			i++;
		if (!s[i])
			break ;
		count++;
		while (s[i] && s[i] != ' ')
		{
			if (s[i] == '\'' || s[i] == '"')
			{
				quote = s[i++];
				while (s[i] && s[i] != quote)
					i++;
				if (s[i] == quote)
					i++;
			}
			else
				i++;
		}
	}
	return (count);
}

static int	cmd_len(char *s, int start, int end)
{
	int		len;
	char	quote;

	len = 0;
	while (start < end)
	{
		if (s[start] == '\'' || s[start] == '"')
		{
			quote = s[start++];
			while (start < end && s[start] != quote)
			{
				len++;
				start++;
			}
			if (start < end && s[start] == quote)
				start++;
		}
		else
		{
			len++;
			start++;
		}
	}
	return (len);
}

static int	find_cmd_end(char *s, int start)
{
	int		end;
	char	quote;

	end = start;
	while (s[end] && s[end] != ' ')
	{
		if (s[end] == '\'' || s[end] == '"')
		{
			quote = s[end++];
			while (s[end] && s[end] != quote)
				end++;
			if (s[end] == quote)
				end++;
		}
		else
			end++;
	}
	return (end);
}

static int	fill_str(char *dst, char *s, int i, int end)
{
	int		j;
	char	quote;

	j = 0;
	while (i < end)
	{
		if (s[i] == '\'' || s[i] == '"')
		{
			quote = s[i++];
			while (i < end && s[i] != quote)
				dst[j++] = s[i++];
			if (i < end && s[i] == quote)
				i++;
		}
		else
			dst[j++] = s[i++];
	}
	dst[j] = '\0';
	return (j);
}

char	*extract_string(char *s, int *ptr_i, int i)
{
	char	*str;
	int		end;
	int		len;

	i = *ptr_i;
	while (s[i] == ' ')
		i++;
	if (!s[i])
	{
		*ptr_i = i;
		return (NULL);
	}
	end = find_cmd_end(s, i);
	len = cmd_len(s, i, end);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	fill_str(str, s, i, end);
	*ptr_i = end;
	return (str);
}
