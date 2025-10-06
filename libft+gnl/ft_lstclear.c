/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:55:04 by rogde-so          #+#    #+#             */
/*   Updated: 2025/04/22 14:35:26 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* static void	del(void *ptr)
{
	free(ptr);
} */
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	if (*lst != NULL)
	{
		while ((*lst)->next != NULL)
		{
			temp = (*lst)->next;
			del((*lst)->content);
			free(*lst);
			*lst = temp;
		}
		del((*lst)->content);
		free(*lst);
		*lst = NULL;
	}
}
/*int main(void)
{
	t_list *list = NULL;
	t_list *head = list;
	t_list *node1 = malloc(sizeof(t_list));
	t_list *node2 = malloc(sizeof(t_list));
	t_list *node3 = malloc(sizeof(t_list));

	node1->content = "Hello";
	node1->next = NULL;

	node2->content = "World";
	node2->next = NULL;

	node3->content = "!";
	node3->next = NULL;

	ft_lstadd_front(&list, node1);
	ft_lstadd_front(&list, node2);
	ft_lstadd_front(&list, node3);

	while (list)
	{
		printf("%s\n", (char *)list->content);
		list = list->next;
	}
	ft_lstclear(&head, del);
	printf("%p", head);

	return (0);
} */