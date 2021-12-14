/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: severi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:38:40 by severi            #+#    #+#             */
/*   Updated: 2021/12/14 14:22:53 by severi           ###   ########.fr       */
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
	char *line;
	int out;
	int p[2];
	int fd;

	out = dup(1);
	pipe(p);

	fd = 1;
	dup2(p[1], fd);
	write(1, "abc\ndef\nghi\njkl\n", 16);
	dup2(out, fd);
	close(p[1]);
	
	printf("TEST: GET_NEXT_LINE: \n");
	printf("TEST 1: ");
	for (int i = 0; i < 4; i++)
	{
		get_next_line(p[0], &line);
		printf(" line0%i: %s", i, line);
	}
	printf(" :TEST END\n");

	write(fd, "aaa", 3);
	close(p[1]);
	dup2(out, fd);
	printf("TEST 2: ");
	get_next_line(p[0], &line);
	printf(" get_next_line() = \"%s\" ", line);
	printf(" :TEST END\n");
	
//	int res = 1;
//
//
// line = malloc(4096);
	
		
/*	while (res)
	{
		res = get_next_line(1, line);
		//ft_putstr_fd(line, 1);
	}
*/	
/*	FILE *fptr;

	fptr = fopen("tests/test_file.txt", "r");
	if (fptr == NULL)
	{
		ft_putstr("Error opening the file");
		exit(1);
	}

	if(!get_next_line(1, line))
		return (-1);

	fclose(fptr);
*/	return (0);
}
