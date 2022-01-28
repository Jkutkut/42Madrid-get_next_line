/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jre-gonz <jre-gonz@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 10:37:34 by jkutkut           #+#    #+#             */
/*   Updated: 2022/01/28 12:01:07 by jre-gonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int f = open("get_next_line_main.c", O_RDWR);

	printf("l: \"%s\"", get_next_line(f));
	printf("l: \"%s\"", get_next_line(f));
	
	return (0);
}
