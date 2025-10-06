/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 20:59:26 by rogde-so          #+#    #+#             */
/*   Updated: 2025/06/26 21:11:44 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*ptrbuffer = NULL;
	char		*line;
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = 1;
	while (!gnl_strchr(ptrbuffer, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		ptrbuffer = gnl_strjoin(ptrbuffer, buffer);
		if (!ptrbuffer)
			return (NULL);
	}
	if (bytes_read == -1 || !ptrbuffer || *ptrbuffer == '\0')
		return (free(ptrbuffer), ptrbuffer = NULL, NULL);
	line = extract_line(ptrbuffer);
	ptrbuffer = update_ptrbuffer(ptrbuffer, 0, 0);
	return (line);
}

/*int main(void)
{
    int fd = open("readme.txt", O_RDONLY);
    char *line;
	int	calls = 1;

    if (fd == -1)
        return (1);
	line = get_next_line(fd);
    printf("OUTPUTED LINE CALL #%d -> %s", calls, line);
	free(line);
     fgwhile ((line = get_next_line(fd)) != NULL)
    {
        printf("OUTPUTED LINE CALL #%d -> %s", calls, line);
		calls++;
        free(line);
    }
    close(fd);
    return (0);
}*/
