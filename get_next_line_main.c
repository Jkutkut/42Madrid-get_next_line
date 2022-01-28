/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 10:37:34 by jkutkut           #+#    #+#             */
/*   Updated: 2022/01/28 13:47:21 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int f = open("get_next_line_main.c", O_RDWR);

	size_t i = 0;
	char *line;
	while (i++ < 20)
	{
		line = get_next_line(f);
		printf("\"%s\"\n", line);
		free(line);
	}
	return (0);
}
