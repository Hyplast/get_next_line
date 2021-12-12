/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: severi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 01:59:53 by severi            #+#    #+#             */
/*   Updated: 2021/12/05 17:33:27 by severi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	i;
	char			*mem;

	if (s == NULL)
		return (NULL);
	mem = ft_strdup(s);
	i = 0;
	if (mem != NULL)
	{
		while (mem[i] != '\0')
		{
			mem[i] = f(mem[i]);
			i++;
		}
	}
	return (mem);
}
