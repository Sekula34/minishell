/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:05:19 by fseles            #+#    #+#             */
/*   Updated: 2023/11/29 14:05:30 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

//return positon of first equal ('=') in string
//example LANG=en return 4
//if there is no = in or string is NULL return -1;
static int	pos_of_equal(char *string)
{
	int	i;

	i = 0;
	if (string == NULL)
		return (-1);
	while (string[i] != '\0')
	{
		if (string[i] == '=')
			return (i);
		i++;
	}
	return (-1);
}

//!!!alocates and return only part of  string  
//part of string before =(including =)
//example LANGUAGE=en return allocated LANGUAGE=
//if string does not contain '=' return NULL 
char	*get_key(char *string)
{
	int		pos_eq;
	char	*key;

	if (string == NULL)
		return (NULL);
	pos_eq = pos_of_equal(string);
	if (pos_eq == -1)
		return (NULL);
	key = ft_calloc(pos_eq + 2, sizeof(char));
	if (key == NULL)
	{
		perror("key allocation in get_key function fails\n");
		return (NULL);
	}
	ft_strlcpy(key, string, pos_eq + 2);
	return (key);
}

//!!!alocates and return only part of  string  
//part of string after =(without =)
//example LANGUAGE=en return allocated en
//if string does not contain '=' return NULL
//LANG=en
char	*get_value(char *string)
{
	int		pos_eq;
	int		val_size;
	char	*value;

	if (string == NULL)
		return (NULL);
	pos_eq = pos_of_equal(string);
	if (pos_eq == -1)
		return (NULL);
	val_size = ft_strlen(string) - pos_eq;
	value = ft_calloc(val_size, sizeof(char));
	if (value == NULL)
	{
		perror("ft_calloc in get_value failed\n");
		return (NULL);
	}
	ft_strlcpy(value, string + pos_eq + 1, val_size);
	return (value);
}

// int main()
// {
// 	char *string = "Languageen=g";
// 	char *key;
// 	char *value;
// 	key = get_key(string);
// 	value = get_value(string);
// 	printf("%s\n", key);
// 	printf("%s\n", value);
// 	free(value);
// 	free(key);
// }