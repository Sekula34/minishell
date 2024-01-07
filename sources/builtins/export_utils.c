/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:10:42 by fseles            #+#    #+#             */
/*   Updated: 2023/12/04 16:10:43 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

//function that cheks if key is valid 
//if retunr 1 key is valid 
//if retunr 0 key is invalid 
//key is valid if contains only alfanumeric or underscore
//can start with with alphabet or _
int	key_checker(char *string)
{
	char	*key_part;
	int		i;

	if (string == NULL)
		return (-1);
	key_part = get_plain_key(string);
	if (key_part == NULL)
		return (-1);
	i = 0;
	if (ft_isalpha(key_part[0]) == 0 && key_part[0] != '_')
		return (free(key_part), 0);
	while (key_part[i] != '\0')
	{
		if (!ft_isalnum(key_part[i]) && key_part[i] != '_')
			return (free(key_part), 0);
		i++;
	}
	return (free(key_part), 1);
}
