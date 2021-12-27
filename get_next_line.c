/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: severi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:38:17 by severi            #+#    #+#             */
/*   Updated: 2021/12/27 16:04:49 by severi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static int	ft_fnd_endl(const char *s)
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

static int	ft_prev_not_empty(char *static_var, char **line)
{
	int		i;
	char	*sto;

	i = 0;
	if (*static_var == '\n')
		static_var++;
	i = ft_fnd_endl(static_var);
	if (i != -1)
	{
		sto = ft_strnew((size_t)i);
		sto = ft_strncpy(sto, static_var, (size_t)i);
		*line = ft_strdup(sto);
		ft_strdel(&sto);
		static_var = ft_strchr(static_var, '\n');
		return (i);
	}
	return (0);
}

static int	ft_prev_empty(char *buf, char static_var, const int fd, char **line)
{
	char		*sto;
	ssize_t		r_bytes;
	int			i;
	int			stat_len;
	
	i = 0;
	r_bytes = 1;
	stat_len = ft_strlen(static_var);
	while (read(fd, buf, BUFF_SIZE) > 0)
	{
		r_bytes = read(fd, buf, BUFF_SIZE);
		while (buf[i] != '\0' && buf[i] != '\n' && i <= r_bytes)
			i++;
		sto = ft_strnew((size_t)i + stat_len);
		if (stat_len > 0)
			sto = ft_strcpy(sto, static_var);
		if (buf[i] == '\0' || buf[i] == '\n')
		{
			sto = ft_strncpy(sto + stat_len, buf, (size_t)i);
			*line = ft_strdup(sto);
			ft_strdel(&sto);
			sto = ft_strchr(buf, '\n');
			if (sto != NULL)
				static_var = ft_strdup(++sto);
			return (1);
		}
		i = 0;
	}
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE];
	int			i;
	int			stat_len;
	static char	*static_var;

	i = 0;
	stat_len = 0;
	if (static_var != NULL)
	{
		i = ft_prev_not_empty(static_var, line);
		if (i > 0)
			return (1);
	}
	if (ft_prev_empty(buf, static_var, fd, line) == 1)
		return (1);
	return (0);
}
