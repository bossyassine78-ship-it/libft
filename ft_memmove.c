/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-hil <yael-hil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 19:47:03 by username          #+#    #+#             */
/*   Updated: 2026/11/04 15:05:34 by yael-hil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*sr;
	unsigned char		*dest;

	sr = (const unsigned char *) src;
	dest = (unsigned char *) dst;
	if (n == 0)
		return (dest);
	if ((size_t) sr < (size_t) dest)
	{
		i = n;
		while (i > 0)
		{
			--i;
			dest[i] = sr[i];
		}
		return (dest);
	}
	return (ft_memcpy(dst, src, n));
}
