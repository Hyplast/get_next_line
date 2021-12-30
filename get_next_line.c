/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: severi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:38:17 by severi            #+#    #+#             */
/*   Updated: 2021/12/30 16:41:25 by severi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int	ft_look_for_nl(char **static_var, char **line)
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
			//free(static_var);
			*static_var = NULL;
			static_var = NULL;
		}
		return (0);
	}
	sto = ft_strsub(*static_var, 0, (size_t)i);
	*line = ft_strdup(sto);
	ft_strdel(&sto);
	*static_var = ft_strchr(*static_var, '\n');
	return (1);
}

char	*ft_add_to_static(char **static_var, char *cpy_from)
{
	char	*sto;

	if (*static_var == NULL)
	{
		*static_var = ft_strdup(cpy_from);
		return (*static_var);
	}
	sto = ft_strjoin(*static_var, cpy_from);
	*static_var = ft_strdup(sto);
	ft_strdel(&sto);
	return (*static_var);
}

int	get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	int			i;
	static char	*static_var;
	char		*sto;

	while (1)
	{
		i = ft_look_for_nl(&static_var, line);
		if (i == 1)
			return (1);
		i = (int)read(fd, buf, BUFF_SIZE);
		buf[i] = '\0';
		if (i == 0 /*&& static_var == NULL*/)
		{
			if (static_var != NULL)
				*line = ft_strdup(static_var);
			return (0);
		}
		sto = ft_add_to_static(&static_var, buf);
		static_var = strdup(sto);
	}
}
