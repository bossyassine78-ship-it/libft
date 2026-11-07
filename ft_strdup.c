/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-hil <yael-hil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 19:55:19 by username          #+#    #+#             */
/*   Updated: 2026/10/20 19:55:20 by yael-hil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*stock;

	i = 0;
	stock = malloc(ft_strlen(s) + 1);
	if (!stock)
		return (NULL);
	while (s[i])
	{
		stock[i] = s[i];
		i++;
	}
	stock[i] = '\0';
	return (stock);
}
