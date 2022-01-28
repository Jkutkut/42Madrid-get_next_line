/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 10:37:34 by jkutkut           #+#    #+#             */
/*   Updated: 2022/01/28 13:56:09 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"

#define FILE "get_next_line_main.c"
#define OFFSET 15
#define LINES 5

int	main(void)
{
	char *line;
	int f;
	size_t i;
	
	printf("\nFile: ~%s~\n", FILE);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	f = open(FILE, O_RDWR);
	i = 0;
	while (i++ < OFFSET)
	{
		line = get_next_line(f);
		free(line);
	}
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
