/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: severi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:38:40 by severi            #+#    #+#             */
/*   Updated: 2022/01/08 02:39:12 by severi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int	main(int argc, char *argv[])
{
	int read = 1;

	printf("Program %s was called with %i arguments.\n", argv[0] ,argc);
	
	if (argc == 2)
	{
		char *copy;
		int fptr;
		fptr = open(argv[1], O_RDONLY);
		if (fptr < 0)
			exit(EXIT_FAILURE);
		
		while((read = get_next_line(fptr ,&copy)) != 0)
		{
			printf("%s\n", copy);
			free(copy);
		}
		//free(copy);
		close(fptr);
	}
	else 
	{
		char *line;
		int i = -1;
		int j = 0;

		int file_desc = open("tests/test_file_6.txt", O_RDONLY);
	
		if (file_desc < 0)
			printf("Error opening the file\n");
		while (i != 0)
		{
			i = get_next_line(file_desc, &line);
			if (i != 0)
			{
				printf(" line0%i: %s", j++, line);
				free(line);
			}
			else
				printf(" :returned *%i*", i);
		}
		printf("- call  once more: %i, ", get_next_line(file_desc, &line));
		printf(" :TEST END\n");
		close(file_desc);
		//free(line);
	}
	return (0);
}
