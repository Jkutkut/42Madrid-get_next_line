/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 10:05:07 by jkutkut           #+#    #+#             */
/*   Updated: 2022/01/28 13:32:00 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	readChunk(char **cache, int fd)
{
	ssize_t	r;
	char	txt[BUFFER_SIZE + 1];
	char *oldcache;

	r = read(fd, txt, BUFFER_SIZE);
	txt[r] = '\0';
	
	oldcache = *cache;
	*cache = ft_strjoin(oldcache, txt);
	free(oldcache);
	return r;
}

char	*ft_getline(char **cache)
{
	// char	*line;
	return (*cache);
}


char	*get_next_line(int fd)
{
	ssize_t	r;
	static char	*cache = NULL;

	r = readChunk(&cache, fd);
	printf("line: %s\n", ft_getline(&cache));
	printf("chars red: %ld\n", r);
	// printf("\n***********\n- fd: %d\n- txt: \"%s\"\n- bs: %u\n***********\n",
			// fd, cache, BUFFER_SIZE);
	return (NULL);
}
