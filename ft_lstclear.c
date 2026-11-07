/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-hil <yael-hil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 22:23:10 by username          #+#    #+#             */
/*   Updated: 2026/11/01 22:14:24 by yael-hil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cur;
	t_list	*n;

	if (!lst || !del)
		return ;
	cur = *lst;
	while (cur != NULL)
	{
		n = cur->next;
		del(cur->content);
		free(cur);
		cur = n;
	}
	*lst = NULL;
}
