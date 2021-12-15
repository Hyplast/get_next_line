/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: severi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:38:17 by severi            #+#    #+#             */
/*   Updated: 2021/12/15 14:32:58 by ssavukos         ###   ########.fr       */
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
	char		*sto2;
	static int	fnc_called;
	size_t		stat_len;

	stat_len = 0;
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
			sto = ft_strnew((size_t)i);
			sto = ft_strncpy(sto, static_var, (size_t)i);
			*line = ft_strdup(sto);
			ft_strdel(&sto);
			static_var = ft_strchr(static_var, '\n');
			return (1);
		}
		else 
		{
			i = 0;
			stat_len = ft_strlen(static_var);
		}
	}
	while (r_bytes > 0)
	{
		r_bytes = read(fd, buf, BUFF_SIZE);
		
		while (buf[i] != '\0' && buf[i] != '\n' && i <= r_bytes)
		{
			i++;
		}
		sto = ft_strnew((size_t)i + stat_len);
		if (stat_len > 0)
		{
			sto = ft_strcpy(sto, static_var);
		}
		if (buf[i] == '\0' || buf[i] == '\n')
		{
			sto = ft_strncpy(sto + stat_len, buf, (size_t)i);
			*line = ft_strdup(sto);
			ft_strdel(&sto);
			if ((sto2 = ft_strchr(buf, '\n')) != NULL)
			{
				static_var = ft_strdup(++sto2);
				//ft_strdel(&sto2);
			}	
			return (1);
		}
		i = 0;
	}
	return (0);
	return (1);
}
