/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:24:23 by rogde-so          #+#    #+#             */
/*   Updated: 2025/04/22 15:23:10 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] && s != NULL)
	{
		write(fd, &s[i++], 1);
	}
}
/*int	main(int ac, char *av[])
{
	if (ac == 3)
	{
		ft_putstr_fd(av[1], atoi(av[2]));
	}
	return (0);
}*/
