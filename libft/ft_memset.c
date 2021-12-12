/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: severi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 00:29:35 by severi            #+#    #+#             */
/*   Updated: 2021/11/30 12:15:41 by severi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	size_t			i;
	unsigned char	*bytes;

	i = 0;
	bytes = (unsigned char *)s;
	while (i < len)
		bytes[i++] = (unsigned char)c;
	return ((void *)bytes);
}
