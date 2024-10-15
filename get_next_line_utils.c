/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:29:18 by scraeyme          #+#    #+#             */
/*   Updated: 2024/10/15 11:15:15 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

int	has_newline(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = 0;
	free(s1);
	return (str);
}

char	*get_until_newline(char *buffer, int fd)
{
	char	*line;
	int		i;

	i = 1;
	line = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!line)
		return (NULL);
	while (!has_newline(line) && i)
	{
		i = read(fd, line, BUFFER_SIZE);
		if (i == -1)
		{
			free(line);
			return (NULL);
		}
		line[i] = 0;
		buffer = ft_strjoin(buffer, line);
	}
	free(line);
	return (buffer);
}

char	*transform_buffer(char *buffer)
{
	char		*str;
	size_t		i;
	size_t		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	str = malloc(i + 1 + (has_newline(buffer)));
	if (!str)
		return (NULL);
	j = 0;
	while (j < i)
	{
		str[j] = buffer[j];
		j++;
	}
	if (buffer[j] && buffer[j] == '\n')
	{
		str[j] = '\n';
		j++;
	}
	str[j] = 0;
	return (str);
}
