/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:29:24 by scraeyme          #+#    #+#             */
/*   Updated: 2024/10/16 16:35:27 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		has_newline(char *str);
char	*get_until_newline(char *buffer, int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*transform_buffer(char *buffer);
size_t	ft_strlen(char *str);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
char	*free_all(char *buffer, char *line);

#endif