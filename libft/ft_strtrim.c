/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:15:59 by fseles            #+#    #+#             */
/*   Updated: 2023/09/08 10:16:01 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_char_set(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	start_index_check(char const *s1, size_t start_index)
{
	if (start_index == ft_strlen(s1))
		return (0);
	return (start_index);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		start_index;
	size_t		sub_end;
	size_t		i;
	char		*p;

	start_index = 0;
	sub_end = 0;
	i = 0;
	if (s1 == NULL || set == NULL )
		return (NULL);
	while (is_in_char_set (s1[start_index], set))
		start_index ++;
	while (is_in_char_set (s1[ft_strlen(s1) - 1 - sub_end], set))
		sub_end ++;
	start_index = start_index_check(s1, start_index);
	p = ft_calloc (ft_strlen(s1) + 1 - start_index - sub_end, sizeof(char));
	if (p == NULL)
		return (NULL);
	while (start_index < (ft_strlen(s1) - sub_end))
	{
		p[i] = s1[start_index];
		i++;
		start_index++;
	}
	return (p);
}

// #include<stdio.h>
// int main()
// {
// 	char s[] = "   xxxtripouille   xxx";
// 	char s1[] = " x";
// 	char *p1; 
// 	p1 = ft_strtrim(s, s1); 
// 	printf("%s", p1); 
// 	free(p1); 
// 	return (0); 
// }