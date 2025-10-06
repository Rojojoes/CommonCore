/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:24:18 by rogde-so          #+#    #+#             */
/*   Updated: 2025/04/21 18:57:59 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	l;

	l = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		l++;
	}
	return (l);
}
/* int main(void)
{
	t_list *list = NULL;
	t_list *node1 = malloc(sizeof(t_list));
	t_list *node2 = malloc(sizeof(t_list));

	node1->content = "Hello";
	node1->next = NULL;

	node2->content = "World";
	node2->next = NULL;

	ft_lstadd_back(&list, node1);
	ft_lstadd_back(&list, node2);

	printf("%d", ft_lstsize(list));

	return (0);
} */
