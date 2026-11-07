/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-hil <yael-hil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 18:11:55 by username          #+#    #+#             */
/*   Updated: 2026/10/24 23:05:30 by yael-hil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_stock;
	char	*stock;
	size_t	valid;

	if (!s1 || !s2)
		return (NULL);
	if (ft_strlen(s1) + ft_strlen(s2) == 0)
		return (ft_strdup(""));
	len_stock = ft_strlen(s1);
	stock = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!stock)
		return (NULL);
	valid = ft_strlcpy(stock, s1, ft_strlen(s1) + 1);
	if (!valid)
	{
		ft_strlcpy(stock, s2, ft_strlen(s2) + 1);
		return (stock);
	}
	ft_strlcat(stock, s2, len_stock + ft_strlen(s2) + 1);
	return (stock);
}
