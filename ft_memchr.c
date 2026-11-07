/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-hil <yael-hil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 19:46:57 by username          #+#    #+#             */
/*   Updated: 2026/10/30 01:10:23 by yael-hil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*find;
	size_t				i;

	i = 0;
	find = (const unsigned char *) s;
	if (!find || n == 0)
		return (NULL);
	while (i < n)
	{
		if (find[i] == (unsigned char) c)
			return ((void *) & find[i]);
		i++;
	}
	return (NULL);
}
