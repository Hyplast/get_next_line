/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: severi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 22:18:58 by severi            #+#    #+#             */
/*   Updated: 2021/12/06 14:24:09 by severi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*subs;

	i = 0;
	if (s == NULL || start > ft_strlen(s) || len > ft_strlen(s))
		return (NULL);
	subs = ft_strnew(len);
	if (subs == NULL)
		return (NULL);
	while (i < len)
	{
		subs[i] = s[start + i];
		i++;
	}
	return (subs);
}
