/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-hil <yael-hil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 18:55:26 by username          #+#    #+#             */
/*   Updated: 2026/11/01 21:53:49 by yael-hil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	unsigned char	*stock;

	if (count == 0 || size == 0)
		return (malloc(1));
	if (count > (size_t)-1 / size)
		return (NULL);
	stock = malloc(count * size);
	if (!stock)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		stock[i] = 0;
		i++;
	}
	return (stock);
}
