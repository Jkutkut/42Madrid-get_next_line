/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 10:05:58 by jkutkut           #+#    #+#             */
/*   Updated: 2022/01/28 12:57:33 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_chunk	*ft_lstnew(char *content)
{
	t_chunk	*e;

	e = malloc(sizeof(t_chunk));
	if (e == NULL)
		return (NULL);
	e->content = content;
	e->next = NULL;
	return (e);
}

t_chunk	*ft_lstlast(t_chunk *lst)
{
	if (lst == NULL)
		return (NULL);
	if (lst->next != NULL)
		return (ft_lstlast(lst->next));
	return (lst);
}

void	ft_lstadd_back(t_chunk **lst, t_chunk *new)
{
	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}


size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (*(s + l))
		l++;
	return (l);
}


size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_l;

	i = 0;
	dst_l = ft_strlen(src);
	if (size == 0)
		return (dst_l);
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst_l);
}


char	*ft_strdup(const char *s)
{
	char	*str;

	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s, ft_strlen(s) + 1);
	return (str);
}
