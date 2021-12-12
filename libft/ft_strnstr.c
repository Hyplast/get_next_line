/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: severi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:50:42 by severi            #+#    #+#             */
/*   Updated: 2021/12/03 16:54:36 by severi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	needle_len;

	i = 0;
	needle_len = ft_strlen(needle);
	if (haystack[0] == '\0' && needle[0] == '\0')
		return ((char *)(haystack + i));
	if ((n == 0 && needle[0] != '\0') || needle_len > ft_strlen(haystack))
		return (NULL);
	if (!(needle_len))
		return ((char *) haystack);
	while ((n - needle_len) >= i)
	{
		if (ft_strncmp(((char *) haystack + i), needle, needle_len) == 0)
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
