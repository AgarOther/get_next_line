/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 09:22:22 by scraeyme          #+#    #+#             */
/*   Updated: 2024/10/14 10:38:58 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_realloc(char *s, size_t newsize)
{
	char		*new;
	size_t		i;

	new = malloc(newsize);
	if (!new)
		return (NULL);
	i = 0;
	if (s)
	{
		while (s[i] && i < newsize)
		{
			new[i] = s[i];
			i++;
		}
		free(s);
	}
	new[newsize - 1] = 0;
	return (new);
}

int	has_newline(char *str)
{
	int	i;

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

size_t	get_chars_until_newline(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i + 1);
}
