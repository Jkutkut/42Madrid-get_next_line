/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 10:05:58 by jkutkut           #+#    #+#             */
/*   Updated: 2022/09/20 14:11:01 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_gnl_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (*(s + l))
		l++;
	return (l);
}

size_t	ft_gnl_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_l;

	i = 0;
	dst_l = ft_gnl_strlen(src);
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

char	*ft_gnl_strdup(const char *s)
{
	char	*str;

	str = malloc(sizeof(char) * (ft_gnl_strlen(s) + 1));
	if (str == NULL)
		return (NULL);
	ft_gnl_strlcpy(str, s, ft_gnl_strlen(s) + 1);
	return (str);
}

char	*ft_gnl_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;

	if (s1 == NULL)
	{
		if (s2 == NULL)
			return (NULL);
		return (ft_gnl_strdup(s2));
	}
	if (s2 == NULL)
		return (ft_gnl_strdup(s1));
	s1_len = ft_gnl_strlen(s1);
	s2_len = ft_gnl_strlen(s2);
	str = (char *) malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (str == NULL)
		return (NULL);
	ft_gnl_strlcpy(str, s1, s1_len + 1);
	ft_gnl_strlcpy(str + s1_len, s2, s2_len + 1);
	return (str);
}

char	*ft_gnl_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	strlen;

	if (s == NULL)
		return (NULL);
	strlen = ft_gnl_strlen(s);
	if (start > strlen)
	{
		str = malloc(sizeof(char));
		if (str != NULL)
			str[0] = '\0';
		return (str);
	}
	if (len > strlen - start)
		len = strlen - start;
	str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	ft_gnl_strlcpy(str, s + start, len + 1);
	return (str);
}
