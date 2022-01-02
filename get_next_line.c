/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: severi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:38:17 by severi            #+#    #+#             */
/*   Updated: 2022/01/03 00:06:32 by severi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static int	ft_look_for_nl(char **static_var, char **line)
{
	int		i;
	char	*sto;	

	i = 0;
	if (*static_var == NULL)
		return (0);
	if (*static_var[0] == '\n')
		*static_var = *static_var + 1;
	while (static_var[0][i] != '\0' && static_var[0][i] != '\n')
			i++;
	if (static_var[0][i] == '\0')
	{
		if (*static_var[0] == '\0')
		{
			*static_var = NULL;
		}
		return (0);
	}
	sto = ft_strsub(*static_var, 0, (size_t)i);
	*line = ft_strdup(sto);
	ft_strdel(&sto);
	*static_var = ft_strchr(*static_var, '\n');
	return (1);
}

static void	ft_add_to_static(char **static_var, char *buf)
{
	char	*sto;

	if (*static_var == NULL)
		*static_var = ft_strdup(buf);
	else
	{
		sto = ft_strjoin(*static_var, buf);
		*static_var = ft_strdup(sto);
		ft_strdel(&sto);
	}
}

static int	ft_set_and_free(char **static_var, char **line)
{
	*line = ft_strdup(*static_var);
	*static_var = NULL;
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	int			i;
	static char	*static_var[4096];

	if (fd < 0 || fd >= 4096 || line == NULL)
		return (-1);
	while (1)
	{
		i = ft_look_for_nl(&static_var[fd], line);
		if (i == 1)
			return (1);
		i = (int)read(fd, buf, BUFF_SIZE);
		if (i == 0 || i == -1)
		{
			if (static_var[fd] != NULL)
				return (ft_set_and_free(&static_var[fd], line));
			return (i);
		}
		buf[i] = '\0';
		ft_add_to_static(&static_var[fd], buf);
	}
}
