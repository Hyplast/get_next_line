/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: severi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 23:47:48 by severi            #+#    #+#             */
/*   Updated: 2021/12/05 14:56:05 by severi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_digits(long c)
{
	size_t	digits;

	digits = 0;
	if (c <= 0)
	{
		digits++;
		c *= -1;
	}
	while (c > 0)
	{
		digits++;
		c /= 10;
	}
	return (digits);
}

char	*ft_itoa(int c)
{
	char	*s;
	size_t	digits;
	long	value;

	value = c;
	digits = count_digits(value);
	s = ft_strnew(digits);
	if (s == NULL)
		return (NULL);
	if (c < 0)
	{
		s[0] = '-';
		value *= -1;
	}
	if (c == 0)
		s[0] = '0';
	while (value > 0)
	{
		s[--digits] = (char)((value % 10) + '0');
		value /= 10;
	}
	return (s);
}
