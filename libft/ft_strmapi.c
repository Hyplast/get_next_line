/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: severi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 02:11:22 by severi            #+#    #+#             */
/*   Updated: 2021/12/05 17:38:53 by severi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*mem;

	if (s == NULL || f == NULL)
		return (NULL);
	mem = ft_strdup(s);
	i = 0;
	if (mem != NULL)
	{
		while (mem[i] != '\0')
		{
			mem[i] = f(i, mem[i]);
			i++;
		}
	}
	return (mem);
}
