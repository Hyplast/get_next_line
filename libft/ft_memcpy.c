/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: severi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 01:08:31 by severi            #+#    #+#             */
/*   Updated: 2021/12/06 17:24:09 by severi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	size_t		i;
	const char	*s;
	char		*d;

	i = 0;
	s = (const char *)src;
	d = (char *)dest;
	while (i < size && (src != NULL || dest != NULL))
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
