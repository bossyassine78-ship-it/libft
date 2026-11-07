/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-hil <yael-hil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 20:07:21 by username          #+#    #+#             */
/*   Updated: 2026/11/02 13:34:25 by yael-hil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*stock;

	i = 0;
	if ((unsigned char) c == '\0')
	{
		while (s[i])
			i++;
		return ((char *) & s[i]);
	}
	while (s[i])
	{
		if ((unsigned char) s[i] == (unsigned char) c)
		{
			stock = (char *) & s[i];
			return (stock);
		}
		i++;
	}
	return (NULL);
}
