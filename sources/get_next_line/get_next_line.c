/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:57:17 by wvan-der          #+#    #+#             */
/*   Updated: 2024/01/15 14:02:07 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../../headers/get_next_line.h"
#include "../../headers/minishel.h"

static char	*ft_gnl_free(int bytes_read, char **line)
{
	if (bytes_read <= 0)
	{
		if (*line)
			free(*line);
		*line = NULL;
	}
	return (NULL);
}

char	*ft_realloc(char **line, int i, int *did_malloc_fail)
{
	int		j;
	char	*temp;

	temp = (char *)ft_calloc(ft_strlen(*line) - check_newline(*line), 1);
	if (!temp)
	{
		*did_malloc_fail = 1;
		return (NULL);
	}
	j = 0;
	while ((*line)[i])
		temp[j++] = (*line)[i++];
	temp[j] = 0;
	free(*line);
	*line = ft_calloc(1, j + 1);
	if (!*line)
		return (free(temp), NULL);
	i = -1;
	while (temp[++i])
		(*line)[i] = temp[i];
	(*line)[i] = 0;
	if (i == 0)
		return (free(temp), ft_gnl_free(-1, line), NULL);
	return (free(temp), *line);
}

char	*make_res(char **line)
{
	char	*res;
	int		i;
	int		did_malloc_fail;

	i = 0;
	did_malloc_fail = 0;
	res = malloc(check_newline_res(*line) + 1);
	if (!res)
		return (ft_gnl_free(-1, line), NULL);
	while ((*line)[i] && (*line)[i] != '\n')
	{
		res[i] = (*line)[i];
		i++;
	}
	res[i] = (*line)[i];
	if ((*line)[i] == '\n')
		res[++i] = '\0';
	ft_realloc(line, i, &did_malloc_fail);
	if (did_malloc_fail)
		return (free(res), ft_gnl_free(-1, line), NULL);
	return (res);
}

char	*ft_read(char **line, int fd, int *bytes_read)
{
	char		*buff;
	char		*temp;

	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
	{
		if (*line)
			free(*line);
		return (NULL);
	}
	*bytes_read = 1;
	while (check_newline(*line) == -1 && *bytes_read != 0)
	{
		*bytes_read = read(fd, buff, BUFFER_SIZE);
		if (*bytes_read <= 0)
			return (free(buff), *line);
		buff[*bytes_read] = '\0';
		temp = ft_strjoin(*line, buff);
		if (*line)
			free(*line);
		*line = temp;
		if (!*line)
			return (free(buff), NULL);
	}
	return (free(buff), *line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*res;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_read(&line, fd, &bytes_read);
	if (bytes_read == -1 || !line)
		return (ft_gnl_free(bytes_read, &line), NULL);
	res = make_res(&line);
	if (!res)
		return (ft_gnl_free(bytes_read, &line), NULL);
	if (bytes_read == 0)
	{
		if (line)
			free(line);
		line = NULL;
	}
	if (res && res[0] == '\0')
		return (free(res), NULL);
	return (res);
}
/* 
int	main()
{
	char *line;
	int fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	int i = 0;

	while(i < 10)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		i++;
	}
	close (fd);
	return (0);
} */
