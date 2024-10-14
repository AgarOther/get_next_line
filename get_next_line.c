/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 09:22:00 by scraeyme          #+#    #+#             */
/*   Updated: 2024/10/14 11:01:53 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static size_t	line_index = 0;
	
}

#include <stdio.h>
#include <fcntl.h>
int	main(void)
{
	int		fd;
	char	*str;

	fd = 0;
	str = get_next_line(open("test.txt", fd));
	printf("%s", str);
	str = get_next_line(open("test.txt", fd));
	printf("%s", str);
	free(str);
}
