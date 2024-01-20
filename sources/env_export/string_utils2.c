/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 13:13:12 by fseles            #+#    #+#             */
/*   Updated: 2024/01/20 13:13:14 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

static void	copy_no_qutes(char *full_string, char *no_qutes)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (full_string[i] != '\0')
	{
		if (full_string[i] != '"')
		{
			no_qutes[j] = full_string[i];
			j++;
		}
		i++;
	}
}

static int	get_number_of_quotes(char *str)
{
	int	i;
	int	number_of_quetes;

	i = 0;
	number_of_quetes = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '"')
			number_of_quetes++;
		i++;
	}
	return (number_of_quetes);
}

int	set_value_without_quotes(char **value, char *value_part_of_string)
{
	int	number_of_quetes;
	int	no_qutes_len;

	number_of_quetes = get_number_of_quotes(value_part_of_string);
	no_qutes_len = ft_strlen(value_part_of_string) - number_of_quetes;
	if (no_qutes_len == 0)
	{
		*value = NULL;
		return (0);
	}
	*value = ft_calloc(no_qutes_len + 1, sizeof(char));
	if (*value == NULL)
	{
		perror("ft_calloc in set_value_without_quotes failed\n");
		return (1);
	}
	copy_no_qutes(value_part_of_string, *value);
	return (0);
}
