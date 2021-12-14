/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: severi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:38:17 by severi            #+#    #+#             */
/*   Updated: 2021/12/14 14:17:57 by severi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int static	ft_fnd_endl(const char *s)
{
	int	end;
	int	loc;

	loc = -1;
	end = 0;
	while (*s != '\0' && *s != '\n')
	{
		s++;
		end++;
	}
	if (*s == '\n')
		loc = end;
	return (loc);
}

int			get_next_line(const int fd, char **line)
{
	
	char		buf[BUFF_SIZE];
	ssize_t		r_bytes;
	int			i;
	static char	*static_var;
	char		*sto;
	static int	fnc_called;

	
	ft_putnbr(fnc_called++);
	ft_putstr(" - called this many times\n");
	r_bytes = 1;
	i = 0;
	//if (**line == NULL)
	//	return (-1);
	if (static_var != NULL)
	{
		if (*static_var == '\n')
			static_var++;
		if((i = ft_fnd_endl(static_var)) != -1)
		{
			*line = ft_strncpy(*line, static_var, (size_t)i);
			static_var = ft_strchr(static_var, '\n');
			return (1);
		}
		

	}
	while (r_bytes > 0)
	{
		r_bytes = read(fd, buf, BUFF_SIZE);
		
		while (buf[i] != '\0' && buf[i] != '\n' && i <= r_bytes)
		{
			i++;
		}
		if (buf[i] == '\0' || buf[i] == '\n')
		{
			*line = ft_strncpy(*line, buf, (size_t)i);
			if ((sto = ft_strchr(buf, '\n')) != NULL)
			{
				static_var = ft_strdup(sto);
			}	
			return (1);
		}
		i = 0;
	}
	return (0);
	return (1);
}
