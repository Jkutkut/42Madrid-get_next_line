/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 10:37:34 by jkutkut           #+#    #+#             */
/*   Updated: 2022/01/28 16:54:30 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"

#define FILE "get_next_line_main.c"
#define OFFSET 1
#define LINES 53

int	main(void)
{
	char *line;
	int f;
	size_t i;
	
	printf("\nFile: ~%s~\n", FILE);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

	if ((f = open(FILE, O_RDWR)) == -1)
	{
		printf("file opening failed\n");
		exit(0);
	}
	i = 0;
	while (i++ < OFFSET)
	{
		line = get_next_line(f);
		free(line);
	}
	
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	i = 0;
	while (i++ < LINES)
	{
		line = get_next_line(f);
		printf("~%s~\n", line);
		free(line);
	}
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	return (0);
}
