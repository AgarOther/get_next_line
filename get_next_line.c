/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:29:22 by scraeyme          #+#    #+#             */
/*   Updated: 2024/10/15 19:18:16 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	char	*val;
	size_t	i;

	i = 0;
	val = (char *) s;
	while (i < n)
	{
		val[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;
	size_t	memsize;

	if ((unsigned long long) nmemb * size > 4294967295)
		return (NULL);
	if (nmemb == 0 || size == 0)
	{
		result = malloc(0);
		if (!result)
			return (NULL);
		return (result);
	}
	if ((long) nmemb < 0 || (long) size < 0)
		return (NULL);
	memsize = nmemb * size;
	result = malloc(memsize);
	if (!result)
		return (NULL);
	ft_bzero(result, memsize);
	return (result);
}

char	*get_next_buffer(char *buffer)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i])
		i++;
	str = malloc(ft_strlen(&buffer[i]) + 1);
	if (!str)
		return (NULL);
	while (buffer[i])
	{
		str[j] = buffer[i];
		i++;
		j++;
	}
	str[j] = 0;
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (!buffer)
	{
		buffer = malloc(1);
		if (!buffer)
			return (NULL);
		buffer[0] = 0;
	}
	buffer = get_until_newline(buffer, fd);
	if (!buffer)
		return (NULL);
	line = transform_buffer(buffer);
	if (!line)
		return (NULL);
	buffer = get_next_buffer(buffer);
	return (line);
}
// #include <stdio.h>
// int	main(void)
// {
// 	int	fd;

// 	fd = open("test.txt", O_RDONLY);
// 	char *s = get_next_line(fd);
// 	printf("%s", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("%s", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("%s", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("%s", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("%s", s);
// 	free(s);
// 	// s = get_next_line(fd);
// 	// printf("%s", s);
// 	// free(s);
// 	// s = get_next_line(fd);
// 	// printf("%s", s);
// 	// free(s);
// 	// s = get_next_line(fd);
// 	// printf("%s", s);
// 	// free(s);
// 	close(fd);
// }
