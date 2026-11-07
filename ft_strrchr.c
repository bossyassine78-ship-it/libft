/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strrchr.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/20 19:55:52 by username         #+#    #+#              */
/*   Updated: 2026/10/31 05:04:53 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*rtrn;
	size_t	i;
	char	cc;

	i = 0;
	cc = (char) c;
	rtrn = NULL;
	while (s[i])
	{
		if (s[i] == cc)
		{
			rtrn = (char *) & s[i];
		}
		i++;
	}
	if (cc == '\0')
	{
		rtrn = (char *) & s[i];
		return (rtrn);
	}
	return (rtrn);
}
