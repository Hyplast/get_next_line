/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: severi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:59:05 by severi            #+#    #+#             */
/*   Updated: 2021/11/21 13:17:18 by severi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	d_len;
	size_t	s_len;

	i = 0;
	d_len = 0;
	s_len = ft_strlen(src);
	while (d_len < size && dest[d_len] != '\0')
		d_len++;
	j = size - d_len - 1;
	if (d_len == size)
		return (s_len + size);
	while (j > 0 && src[i] != '\0')
	{
		dest[d_len + i] = src[i];
		i++;
		j--;
	}
	if (dest[d_len + i] != '\0')
		dest[d_len + i] = '\0';
	return (s_len + d_len);
}
