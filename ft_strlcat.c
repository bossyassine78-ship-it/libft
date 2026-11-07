/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-hil <yael-hil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 02:56:29 by username          #+#    #+#             */
/*   Updated: 2026/10/21 02:57:44 by yael-hil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	start;
	size_t	i;
	size_t	srclen;

	i = 0;
	start = 0;
	srclen = ft_strlen(src);
	while (start < dstsize && dst[start])
		start++;
	if (start == dstsize)
		return (dstsize + srclen);
	while (i < dstsize - start - 1 && src[i])
	{
		dst[start + i] = src[i];
		i++;
	}
	dst[start + i] = '\0';
	return (start + srclen);
}
