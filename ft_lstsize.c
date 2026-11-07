/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_lstsize.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/29 02:11:37 by username         #+#    #+#              */
/*   Updated: 2026/10/31 16:30:21 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_lstsize(t_list *lst)
{
	t_list			*cur;
	unsigned int	count;

	if (!lst)
		return (0);
	cur = lst;
	count = 0;
	while (cur != NULL)
	{
		cur = cur->next;
		count++;
	}
	return (count);
}
