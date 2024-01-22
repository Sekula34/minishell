/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 10:43:21 by wvan-der          #+#    #+#             */
/*   Updated: 2024/01/22 11:30:21 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/get_next_line.h"

int	check_newline_res(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (-1);
	while (line[i])
	{
		if (line[i] == '\n')
		{
			return (i + 1);
		}
		i++;
	}
	return (i);
}

int	check_newline(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (-1);
	while (line[i])
	{
		if (line[i] == '\n')
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

void	*ft_calloc(size_t nitems, size_t size)
{
	char		*res;
	long long	test;
	size_t		i;

	i = 0;
	test = nitems * size;
	if (test > 2147483647)
		return (NULL);
	res = malloc(nitems * size);
	if (res == NULL)
		return (NULL);
	while (i < nitems * size)
	{
		res[i] = 0;
		i++;
	}
	return (res);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		total_len;
	char	*res;
	int		i;
	int		j;

	i = -1;
	j = 0;
	total_len = ft_strlen(s1) + ft_strlen(s2);
	res = ft_calloc(1, total_len + 1);
	if (!res || !s2)
		return (NULL);
	if (s1)
	{
		while (s1[++i])
			res[i] = s1[i];
		i--;
	}
	i++;
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = 0;
	return (res);
}

/* int main()
{
	char *s1 = "hello";
	char *s2 = "world";

	printf("%s", ft_strjoin(s1, s2));
} */
