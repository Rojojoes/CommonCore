/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogde-so <rogde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:35:50 by rogde-so          #+#    #+#             */
/*   Updated: 2025/04/22 14:39:34 by rogde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*static void	del(void *something)
{
	free(something);
}*/
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst != NULL && del != NULL)
	{
		del(lst->content);
		free(lst);
	}
	return ;
}
/* int main(void)
{
	t_list *list = ft_lstnew(ft_strdup("Hello"));
	list->next = ft_lstnew(ft_strdup("World"));
	list->next->next = ft_lstnew(ft_strdup("wassup"));

	t_list	*temp = list;
	while (temp != NULL)
	{
		printf("%s ->", (char *)temp->content);
		temp = temp->next;
	}
	printf("\n");
	t_list	*deleteme = list;
	list = list->next;
	ft_lstdelone(deleteme, del);
	temp = list;
	while (temp != NULL)
	{
		printf("%s ->", (char *)temp->content);
		temp = temp->next;
	}

	return (0);
} */