/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: severi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:38:40 by severi            #+#    #+#             */
/*   Updated: 2021/12/30 14:30:13 by severi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	/*char **str = {"Hello, this is my world\n", 
"and my world only. Those who can read\n", 
"will be allowed to stay\n", "\n"}
	char **line;
*/
	int read = 1;
	if (argc == 2)
	{
		char *copy;
		FILE *fptr;
		fptr = fopen(argv[1], "r");
		if (fptr == NULL)
			exit(EXIT_FAILURE);
		copy = (char*)fptr;
		while((read = get_next_line(1 ,&copy)) != 0)
		{
			printf("%s", copy);
		}
		fclose(fptr);
	}
	char *line;
	int out;
	int p[2];
	int fd;
	int i = -1;
	int j = 0;
	
	out = dup(1);
	pipe(p);

	fd = 1;
	dup2(p[1], fd);
	write(1, "abc\ndef\nghi\njkl\n", 16);
	dup2(out, fd);
	close(p[1]);
	
	printf("TEST: GET_NEXT_LINE: \n");
	printf("TEST 1: ");
	while (i != 0)
	{
		i = get_next_line(p[0], &line);
		if (i != 0)
			printf(" line0%i: %s", j++, line);
		else
			printf(" returned 0");
	}
	printf(" :TEST END\n");
/*
	dup2(p[1], fd);
	write(1, "aaa", 3);
	close(p[1]);
	dup2(out, fd);
	printf("TEST 2: ");
	get_next_line(p[0], &line);
	printf(" get_next_line() = \"%s\" ", line);
	printf(" :TEST END\n");
	*/
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
