/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: severi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:18:41 by severi            #+#    #+#             */
/*   Updated: 2021/11/14 20:44:20 by severi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	len;

	if (ft_strlen(s1) > ft_strlen(s2))
		len = ft_strlen(s1);
	else
		len = ft_strlen(s2);
	return (ft_strncmp(s1, s2, len));
}		
