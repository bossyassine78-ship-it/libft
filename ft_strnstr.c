/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-hil <yael-hil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 01:40:52 by username          #+#    #+#             */
/*   Updated: 2026/10/21 02:21:56 by yael-hil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t				i;
	size_t				j;
	const unsigned char	*stock;

	i = 0;
	j = 0;
	if (!little[j])
		return ((char *) big);
	while (i < len && big[i])
	{
		if (big[i] == little[j])
			stock = (const unsigned char *) & big[i];
		while (little[j] && (i + j) < len && big[i + j] == little[j])
			j++;
		if (!little[j])
			return ((char *) stock);
		j = 0;
		i++;
	}
	return (NULL);
}
