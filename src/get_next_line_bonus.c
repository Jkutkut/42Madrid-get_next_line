/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 10:05:07 by jkutkut           #+#    #+#             */
/*   Updated: 2022/09/20 14:10:54 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

ssize_t	ft_gnl_readchunk(char **cache, int fd)
{
	ssize_t	r;
	char	txt[BUFFER_SIZE + 1];
	char	*oldcache;

	r = read(fd, txt, BUFFER_SIZE);
	if (r <= 0)
		return (r);
	txt[r] = '\0';
	oldcache = *cache;
	*cache = ft_gnl_strjoin(oldcache, txt);
	free(oldcache);
	return (r);
}

char	*ft_gnl_getline(char **cache)
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
	line = ft_gnl_substr(*cache, 0, i + 1);
	if (ft_gnl_strlen(*cache) - i == 0)
		tmp = NULL;
	else
		tmp = ft_gnl_substr(*cache, i + 1, ft_gnl_strlen(*cache) - i);
	free(*cache);
	*cache = tmp;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*cache[OPEN_MAX];
	ssize_t		r;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > OPEN_MAX)
		return (NULL);
	line = NULL;
	while (line == NULL)
	{
		line = ft_gnl_getline(&cache[fd]);
		if (line == NULL)
		{
			r = ft_gnl_readchunk(&cache[fd], fd);
			if (r <= 0)
			{
				if (r == 0 && cache[fd] != NULL && ft_gnl_strlen(cache[fd]) > 0)
					line = ft_gnl_strdup(cache[fd]);
				free(cache[fd]);
				cache[fd] = NULL;
				break ;
			}
		}
	}
	return (line);
}
