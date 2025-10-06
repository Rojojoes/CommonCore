/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:01:18 by rogde-so          #+#    #+#             */
/*   Updated: 2025/04/22 15:11:03 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*void	moveascii_1(unsigned int i, char *str)
{
	if (str[i] >= 33 && str[i] <= 125)
		str[i] += 1;
}*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*int	main(int ac, char *av[])
{
	if (ac == 2)
	{
		printf("%s\n", av[1]);
		ft_striteri(av[1], moveascii_1);
		printf("%s\n", av[1]);
	}
	return (0);
}*/
