/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:48:09 by rogde-so          #+#    #+#             */
/*   Updated: 2025/06/26 16:12:31 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* static void	del(void *ptr)
{
	free(ptr);
}

static void	*f(void *ptr)
{
	*(int *)ptr += 10;
	return (ptr);
} */

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*new_list;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst != NULL)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (new_node == NULL)
		{
			del(new_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

/* int main(void)
{
	t_list *list = NULL;
	t_list *node1 = malloc(sizeof(t_list));
	t_list *node2 = malloc(sizeof(t_list));
	t_list *node3 = malloc(sizeof(t_list));

	node1->content = malloc(sizeof(int));
	node2->content = malloc(sizeof(int));
	node3->content = malloc(sizeof(int));

	list = node1;

	*(int *)node1->content = 10;
	node1->next = node2;

	*(int *)node2->content = 20;
	node2->next = node3;

	*(int *)node3->content = 30;
	node3->next = NULL;

	t_list	*temp = list;
	while (temp != NULL)
	{
		printf("%i ->", *(int *)temp->content);
		temp = temp->next;
	}
	printf("\n");
	t_list	*newlist = ft_lstmap(list, f, del);
	temp = newlist;
	while (temp != NULL)
	{
		printf("%i ->", *(int *)temp->content);
		temp = temp->next;
	}
	return (0);
} */