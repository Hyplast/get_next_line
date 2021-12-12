/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: severi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 02:35:24 by severi            #+#    #+#             */
/*   Updated: 2021/12/06 16:11:37 by severi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest < src)
		ft_memcpy(dest, src, size);
	else
	{
		while (size)
		{
			size--;
			*(unsigned char *)(dest + size) = *(unsigned char *)(src + size);
		}
	}
	return (dest);
}
