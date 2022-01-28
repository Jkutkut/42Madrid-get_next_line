/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 10:05:07 by jkutkut           #+#    #+#             */
/*   Updated: 2022/01/28 13:47:04 by jre-gonz         ###   ########.fr       */
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
	char	*line;
	char	*tmp;
	size_t	i;

	i = 0;
	while ((*cache)[i] && (*cache)[i] != '\n')
		i++;
	if (!(*cache)[i])
		return (NULL);
	line = ft_substr(*cache, 0, i);
	tmp = ft_substr(*cache, i + 1, ft_strlen(*cache) - i);
	free(*cache);
	*cache = tmp;
	return (line);
}


char	*get_next_line(int fd)
{
	ssize_t	r;
	static char	*cache = NULL;
	char	*line;

	readChunk(&cache, fd);
	r = readChunk(&cache, fd);
	if (r == 0)
		return (NULL);
	line = ft_getline(&cache);
	// if (line == NULL)
	// 	return (get_next_line(fd));
	return (line);
}
