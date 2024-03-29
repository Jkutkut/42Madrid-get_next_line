/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 10:00:44 by jkutkut           #+#    #+#             */
/*   Updated: 2022/09/20 14:10:47 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef OPEN_MAX
#  define OPEN_MAX 4096
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

typedef struct s_chunk
{
	char			*content;
	struct s_chunk	*next;
}					t_chunk;

char	*get_next_line(int fd);

size_t	ft_gnl_strlen(const char *s);
size_t	ft_gnl_strlcpy(char *dst, const char *src, size_t size);
char	*ft_gnl_strdup(const char *s);
char	*ft_gnl_strjoin(char const *s1, char const *s2);
char	*ft_gnl_substr(char const *s, unsigned int start, size_t len);

#endif
