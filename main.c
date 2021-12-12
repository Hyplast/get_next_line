/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: severi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:38:40 by severi            #+#    #+#             */
/*   Updated: 2021/12/12 19:10:29 by severi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	/*char **str = {"Hello, this is my world\n", 
"and my world only. Those who can read\n", 
"will be allowed to stay\n", "\n"}
	char **line;
*/
	char **line;
	int res = 1;
	line = malloc(4096);
	while (res)
	{
		res = get_next_line(1, line);
		//ft_putstr_fd(line, 1);
	}
	
	FILE *fptr;

	fptr = fopen("tests/test_file.txt", "r");
	if (fptr == NULL)
	{
		ft_putstr("Error opening the file");
		exit(1);
	}

	if(!get_next_line(1, line))
		return (-1);

	fclose(fptr);
	return (0);
}
