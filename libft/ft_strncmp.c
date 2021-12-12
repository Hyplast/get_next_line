/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: severi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 20:11:14 by severi            #+#    #+#             */
/*   Updated: 2021/12/06 16:10:09 by severi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*c_s1;
	const unsigned char	*c_s2;
	size_t				i;

	i = 0;
	c_s1 = (const unsigned char *)s1;
	c_s2 = (const unsigned char *)s2;
	while (i < n && (c_s1[i] != '\0' || c_s2[i] != '\0'))
	{
		if (c_s1[i] != c_s2[i])
			return ((int)(c_s1[i] - c_s2[i]));
		i++;
	}
	return (0);
}
