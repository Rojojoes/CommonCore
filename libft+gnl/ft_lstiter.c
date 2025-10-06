/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:23:49 by rogde-so          #+#    #+#             */
/*   Updated: 2025/04/22 14:39:34 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* static void	f(void *ptr)
{
	if (ptr == NULL)
		return ;
	printf("%s", (char *)ptr);
} */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst != NULL && f != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/* int main(void)
{
	t_list *list = NULL;
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
	
	t_list *head = list;
	while (head)
	{
		printf("%s\n", (char *)head->content);
		head = head->next;
	}
	printf("\n");
	head = list;
	ft_lstiter(head, f);

	return (0);
} */
