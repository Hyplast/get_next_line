/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: severi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:38:40 by severi            #+#    #+#             */
/*   Updated: 2022/01/01 22:02:15 by severi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include "libft.h"

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

	char 	*str;
	//int		gnl_ret;

	str = (char *)malloc(1000 * 1000);
	*str = '\0';
	ft_strcat(str, "123 Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur in leo dignissim, gravida leo id, imperdiet urna. Aliquam magna nunc, maximus quis eleifend et, scelerisque non dolor. Suspendisse augue augue, tempus");
	ft_strcat(str, "456 Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur in leo dignissim, gravida leo id, imperdiet urna. Aliquam magna nunc, maximus quis eleifend et, scelerisque non dolor. Suspendisse augue augue, tempus");
	ft_strcat(str, "789 Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur in leo dignissim, gravida leo id, imperdiet urna. Aliquam magna nunc, maximus quis eleifend et, scelerisque non dolor. Suspendisse augue augue, tempus");
	
	//printf("\nT*E*S*T* : * %s *\n", str);
	out = dup(1);
	pipe(p);
	
	fd = 1;
	dup2(p[1], fd);

	write(1, str, strlen(str));
	close(p[1]);
	dup2(out, 1);
	//gnl_ret = get_next_line(p[0], &line);
	printf("TEST: GET_NEXT_LINE: \n");
	printf("TEST 3: ");
	while (i != 0)
	{
		i = get_next_line(p[0], &line);
		if (i != 0)
			printf(" line0%i: %s", j++, line);
		else
			printf(" :returned *%i*", i);
	}
	printf("- call  once more: %i, ", get_next_line(p[0], &line));
	printf(" :TEST END\n");

/*	out = dup(1);
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
*/
// /
/*
	i = -1;
	j = 0;
	dup2(p[1], fd);
	write(fd, "aaa", 3);
	close(p[1]);
	dup2(out, fd);
	//printf("TEST 2: ");
//	get_next_line(p[0], &line);
//	printf(" get_next_line() = \"%s\" ", line);
//	get_next_line(p[0], &line);
	
//printf(" get_next_line() = \"%s\" ", line);
	
printf("TEST: GET_NEXT_LINE: \n");
	printf("TEST 2: ");
	while (i != 0)
	{
		i = get_next_line(p[0], &line);
		if (i != 0)
			printf(" line0%i: %s", j++, line);
		else
			printf(" returned 0");
	}
	printf(" :TEST END\n");


	//printf(" :TEST END\n");


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
