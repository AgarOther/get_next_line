/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:29:22 by scraeyme          #+#    #+#             */
/*   Updated: 2024/10/16 17:14:57 by scraeyme         ###   ########.fr       */
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
	memsize = nmemb * size;
	result = malloc(memsize);
	if (!result)
		return (NULL);
	ft_bzero(result, memsize);
	return (result);
}

char	*free_all(char *buffer, char *line)
{
	free(buffer);
	free(line);
	return (NULL);
}

char	*get_next_buffer(char *buffer)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	i++;
	str = ft_calloc(ft_strlen(&buffer[i]) + 1, 1);
	if (!str)
		return (NULL);
	j = 0;
	while (buffer[i])
		str[j++] = buffer[i++];
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
		buffer = ft_calloc(1, 1);
		if (!buffer)
			return (NULL);
	}
	buffer = get_until_newline(buffer, fd);
	if (!buffer || !buffer[0])
		return (NULL);
	line = transform_buffer(buffer);
	buffer = get_next_buffer(buffer);
	return (line);
}
