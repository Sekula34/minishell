/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 10:43:25 by wvan-der          #+#    #+#             */
/*   Updated: 2024/01/16 15:19:48 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 11
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

void	*ft_calloc(size_t nitems, size_t size);
//size_t	ft_strlen(char *s);
//char	*ft_strjoin(char *s1, char *s2);
int		check_newline(char *line);
int		check_newline_res(char *line);
//char	*ft_free(int bytes_read, char **line);
char	*ft_realloc(char **line, int i, int *did_malloc_fail);
char	*make_res(char **line);
char	*ft_read(char **line, int fd, int *bytes_read);
char	*get_next_line(int fd);

#endif
