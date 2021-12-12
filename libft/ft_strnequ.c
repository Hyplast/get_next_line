/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: severi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 22:08:20 by severi            #+#    #+#             */
/*   Updated: 2021/12/05 17:45:32 by severi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(const char *s1, const char *s2, size_t n)
{
	int	result;

	if (s1 == NULL || s2 == NULL)
		return (0);
	result = ft_memcmp(s1, s2, n);
	if (result == 0)
		return (1);
	return (0);
}
