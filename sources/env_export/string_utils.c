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
int	pos_of_equal(char *string)
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

//allocates and return plain part of key
//if key is A56=75
//if key doesnt have equal just copy it
//return A56;
//null if fails
//null if key_with eq is NULL
char *get_plain_key(char *key_with_eq)
{
	char *plain_key;
	int pos_eq;

	if (key_with_eq == NULL)
		return (NULL);
	pos_eq = pos_of_equal(key_with_eq);
	if (pos_eq == -1)
	{
		plain_key = ft_strdup(key_with_eq);
		if(plain_key == NULL)
		{
			perror("ft_strdup in plain key failed\n");
			return (NULL);
		}
		return (plain_key);
	}
	plain_key = ft_substr(key_with_eq, 0, pos_eq);
	if (plain_key == NULL)
	{
		perror("ft_substr in plain key failed\n");
		return (NULL);
	}
	return (plain_key);
}

//allocates key!!
//function that sets key to be part of string 
//if string is LANG=EN
//key will be allocated and set to be copy LANG=;
//if string is NULL key is also NULL
//if allocation fails key will be null and return status will be -1
//if everything is oke return will be 0;
int	set_key(char **key, char *string)
{
	int pos_eq;
	int alloc_size;

	if(string == NULL)
		return (*key = NULL, 0);
	pos_eq = pos_of_equal(string);
	if(pos_eq == -1)
	{
		*key = ft_strjoin(string, "=");
		if(*key == NULL)
			return(-1);
	}
	else 
	{
		alloc_size = pos_eq + 2;
		*key = ft_calloc(alloc_size, sizeof(char));
		if(*key == NULL)
			return(-1);
		ft_strlcpy(*key, string, pos_eq + 2);
	}
	return (0);
}

//!!!alocates value
//if string is ARG or ARG= 
//value is NULL without error (return 0)
//if string is arg=12;
//value is 12 (allllocated);
//return 0 if ok -1 if errror
int set_value(char **value, char *string)
{
	int pos_eq;
	int alloc_size;

	if(string == NULL)
	{
		*value = NULL;
		return (0);
	}
	pos_eq = pos_of_equal(string);
	if(pos_eq == -1 || pos_eq == (int)ft_strlen(string) - 1)
	{
		*value = NULL;
		return (0);
	}
	else
	{
		alloc_size = ft_strlen(string) - pos_eq ;
		*value = ft_calloc(alloc_size, sizeof(char));
		if(*value == NULL)
			return (-1);
		ft_strlcpy(*value, string + pos_eq + 1, alloc_size);
	}
	return (0);
}

//!!!alocates and return only part of  string  
//part of string after =(without =)
//example LANGUAGE=en return allocated en
//if string does not contain '=' return NULL
//LANG=en
//if string is VAL= (val size == 1)
//return NULL
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
	if(val_size == 1)
		return (NULL);
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