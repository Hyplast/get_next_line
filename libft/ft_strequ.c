/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: severi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 22:00:34 by severi            #+#    #+#             */
/*   Updated: 2021/12/05 18:11:58 by severi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(const char *s1, const char *s2)
{
	size_t	len;

	if (s1 == NULL || s2 == NULL)
		return (0);
	if (ft_strlen(s1) > ft_strlen(s2))
		len = ft_strlen(s1);
	else
		len = ft_strlen(s2);
	return (ft_strnequ(s1, s2, len));
}
