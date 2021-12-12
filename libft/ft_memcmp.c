/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: severi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:35:21 by severi            #+#    #+#             */
/*   Updated: 2021/12/06 15:52:42 by severi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*c_s1;
	const unsigned char	*c_s2;
	size_t				i;

	i = 0;
	c_s1 = (const unsigned char *)s1;
	c_s2 = (const unsigned char *)s2;
	while (i < n)
	{
		if (c_s1[i] != c_s2[i])
			return ((int)(c_s1[i] - c_s2[i]));
		i++;
	}
	return (0);
}
