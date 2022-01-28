/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 10:05:07 by jkutkut           #+#    #+#             */
/*   Updated: 2022/01/28 17:00:06 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	readChunk(char **cache, int fd)
{
	ssize_t	r;
	// char	txt[BUFFER_SIZE + 1];
	char	*txt;
	char *oldcache;

	txt = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	r = read(fd, txt, BUFFER_SIZE);
	if (r > 0)
	{
		txt[r] = '\0';
		
		oldcache = *cache;
		*cache = ft_strjoin(oldcache, txt);
		free(oldcache);
	}
	free(txt);
	return r;
}

char	*ft_getline(char **cache)
{
	char	*line;
	char	*tmp;
	size_t	i;

	if (*cache == NULL)
		return (NULL);
	i = 0;
	while ((*cache)[i] && (*cache)[i] != '\n')
		i++;
	if ((*cache)[i] == '\0')
		return (NULL);
	line = ft_substr(*cache, 0, i);
	if (ft_strlen(*cache) - i == 0)
		tmp = NULL;
	else
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

	// readChunk(&cache, fd);
	
	// printf("@@@@@@@@@@@cache@@@@@@@@@@@\"%s\"@@@@@@@@@endcache@@@@@@@@@\n", cache);
	if (fd < 0)
		return (NULL);
	line = NULL;
	while (line == NULL)
	{
		line = ft_getline(&cache);
		if (line == NULL)
		{
			r = readChunk(&cache, fd);
			// printf("r: %d\n", r);
			if (r == 0)
				return (cache);
		}
	}
	return (line);
}
