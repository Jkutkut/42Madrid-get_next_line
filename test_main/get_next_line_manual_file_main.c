/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 11:40:42 by jre-gonz          #+#    #+#             */
/*   Updated: 2022/01/29 13:11:47 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"


int	main(int argc, char **argv)
{
	if (argc != 3)
		return (0);
	
	int fd;
	int i;

	i = atoi(argv[2]);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		printf("Could not open \"%s\"\n", argv[1]);
		exit(0);
	}

	while (--i)
	{
		free(get_next_line(fd));
	}
	char *line = get_next_line(fd);
	printf("%s", line);
	free(line);
	return (0);
}