/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_itoa.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/24 23:03:55 by username         #+#    #+#              */
/*   Updated: 2026/11/04 01:08:21 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	len_n(int n)
{
	int		count;
	long	number;

	number = n;
	count = 1;
	if (number < 0)
		number = -number;
	while (number >= 10)
	{
		number /= 10;
		count++;
	}
	return (count);
}

static long	len_word(long n)
{
	long	count;
	long	number;

	number = n;
	count = 1;
	if (number < 0)
		number = -number;
	while (number >= 10)
	{
		number /= 10;
		count *= 10;
	}
	return (count);
}

static char	*sto(char *stock, long number, int i)
{
	long	total;
	long	digit;

	total = len_word(number);
	while (total > 0)
	{
		digit = number / total;
		stock[i] = (char)(digit + '0');
		i++;
		number %= total;
		total /= 10;
	}
	stock[i] = '\0';
	return (stock);
}

char	*ft_itoa(int n)
{
	char	*stock;
	int		i;
	long	value;

	i = 0;
	stock = malloc(len_n(n) + 2);
	value = n;
	if (!stock)
		return (NULL);
	if (value < 0)
	{
		value = -value;
		stock[i++] = '-';
	}
	return (sto(stock, value, i));
}
