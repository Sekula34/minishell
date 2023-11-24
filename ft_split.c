/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:16:06 by wvan-der          #+#    #+#             */
/*   Updated: 2023/11/24 13:25:06 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishel.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static void	ft_free(char ***res, int a)
{
	if (*res == NULL)
		return ;
	while (a >= 0)
	{
		if ((*res)[a] != NULL)
			free(*(res)[a]);
		a--;
	}
}

static char	*sub_str(char *str, int start, int end)
{
	int		i;
	int		len;
	char	*res;

	i = 0;
	len = end - start + 1;
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	while (start <= end)
	{
		res[i] = str[start];
		i++;
		start++;
	}
	res[i] = 0;
	return (res);
}

static int	word_count(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i] != 0)
			count++;
		while (str[i] && str[i] != ' ')
			i++;
	}
	return (count);
}

static void	ft_init(int *b, int *e, int *a)
{
	*b = 0;
	*e = 0;
	*a = 0;
}

char	**ft_split(char *str)
{
	char	**res;
	int		b;
	int		e;
	int		a;

	ft_init(&b, &e, &a);
	if (!str)
		return (NULL);
	res = malloc(sizeof(char *) * (word_count(str) + 1));
	if (!res)
		return (NULL);
	while (a < word_count(str))
	{
		while (str[b] && str[b] == ' ')
			b++;
		e = b;
		while (str[e] && str[e] != ' ')
			e++;
		res[a] = sub_str(str, b, e - 1);
		if (!res[a++])
			return (ft_free(&res, --a), NULL);
		b = e;
	}
	res[a] = 0;
	return (res);
}
/* 
int main()
{
	char **res;
	int a = 0;
	//printf("%s", sub_str("hello world test", 6, 10));	
	res = ft_split("     hello   world   test   ");
	while (res[a])
	{
		printf("%d: %s\n", a, res[a]);
		free(res[a]);
		a++;
	}
	free(res);
	return (0);
} */
