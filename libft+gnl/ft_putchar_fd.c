/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:14:43 by rogde-so          #+#    #+#             */
/*   Updated: 2025/04/17 17:23:20 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*int	main(int ac, char *av[])
{
	if (ac == 3)
	{
		int	fd = atoi(av[2]);
		char	c = av[1][0];
		ft_putchar_fd(c, fd);
	}
	return (0);
}*/
