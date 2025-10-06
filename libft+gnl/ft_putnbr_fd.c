/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:47:03 by rogde-so          #+#    #+#             */
/*   Updated: 2025/04/20 11:51:09 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	c = n % 10 + '0';
	write(fd, &c, 1);
}
/*void	ft_putnbr_fd(int n, int fd)
{
	char	*nbr;
	int		i;

	i = 0;
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	nbr = ft_itoa(n);
	while (nbr[i])
	{
		write(fd, &nbr[i++], 1);
	}
	free(nbr);
}*/
/*int	main(int ac, char *av[])
{
	if (ac == 3)
	{
		ft_putnbr_fd(atoi(av[1]), atoi(av[2]));
	}
	return (0);
}*/
