/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: severi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:38:17 by severi            #+#    #+#             */
/*   Updated: 2021/12/12 23:51:40 by severi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	
	char		buf[BUFF_SIZE];
	int			r_bytes;
	int			i;
	static char	*static_var;

	r_bytes = 1;
	i = 0;
	if (line || static_var)
		return (-1);
	while (r_bytes > 0)
	{
		r_bytes = read(fd, buf, BUFF_SIZE);
		
		while (buf[i] != '\0' && buf[i] != '\n' && i <= r_bytes)
		{
			i++;
		}
		if (buf[i] == '\0' || buf[i] == '\n')
		{
			ft_strncpy(*line, buf, i);
			return (1);
		}
		i = 0;
	}
	return (0);
	return (1);
}
