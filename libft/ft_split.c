/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 12:08:04 by fseles            #+#    #+#             */
/*   Updated: 2023/09/08 12:08:06 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	number_of_elements(char const *s, char c)
{
	size_t	noe;
	size_t	i;

	i = 0;
	noe = 0;
	if (*s == '\0')
		return (0);
	if (c == '\0')
		return (1);
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			noe ++;
			i++;
			while ((s[i] != c) && (s[i] != '\0'))
				i++;
			if (i >= ft_strlen(s))
				break ;
		}
		i++;
	}
	return (noe);
}

static void	free_arr(char **p)
{
	int	i;

	i = 0;
	while (p[i] != NULL)
	{
		free(p[i]);
		i++;
	}
	free(p);
}

static char	*get_me_word(char const *s, char c)
{
	int		i;
	char	*p;
	int		j;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	p = ft_calloc(i + 1, sizeof(char));
	if (p == NULL)
		return (NULL);
	j = 0;
	while (j < i)
	{
		p[j] = s[j];
		j++;
	}
	return (p);
}

char	**filler(char **p, size_t noe, char const *s, char c)
{
	size_t	j;
	int		i;

	i = 0;
	j = 0;
	while (j < noe)
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		p[j] = get_me_word(&s[i], c);
		if (p[j] == NULL)
		{
			free_arr(p);
			return (NULL);
		}
		j++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	p[j] = NULL;
	return (p);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	size_t	noe;

	noe = number_of_elements(s, c);
	p = malloc (sizeof(char **) * (noe + 1));
	if (p == NULL)
		return (NULL);
	p = filler(p, noe, s, c);
	if (p == NULL)
		return (NULL);
	return (p);
}
// #include "libft.h"
// #include <stdio.h> 

// int main()
// {
// 	//char s1[] = "Filip.a.b..c.";
// 	char **p;
// 	p = ft_split("", 'a');
// 	int i = 0;
// 	while(p != NULL)
// 	{
// 		printf("-> '%s'\n", p[i]);
// 		i++;
// 	}
// 	if (p != NULL)
// 		free_arr(p);
// 	return (0);
// }