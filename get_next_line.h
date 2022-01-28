/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 10:00:44 by jkutkut           #+#    #+#             */
/*   Updated: 2022/01/28 13:02:29 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

#include <stdio.h> // ! TODO DEBUG

typedef struct s_chunk
{
	void			*content;
	struct s_chunk	*next;
}					t_chunk;

char *get_next_line(int fd);
t_chunk	*ft_lstnew(char *content);
t_chunk	*ft_lstlast(t_chunk *lst);
void	ft_lstadd_back(t_chunk **lst, t_chunk *new);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strdup(const char *s);

#endif

