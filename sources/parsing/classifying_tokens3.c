/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classifying_tokens3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:19:59 by wvan-der          #+#    #+#             */
/*   Updated: 2024/01/19 15:20:38 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

int	get_array_size(t_cmd *cmd_lst)
{
	int	size;

	size = 0;
	while (cmd_lst->args && cmd_lst->args[size])
	{
		size++;
	}
	return (size);
}

int	realloc_array(t_tokens *tok, t_cmd **cmd_lst, char *arg)
{
	int		size;
	char	**temp;
	int		i;

	i = 0;
	size = get_array_size(*cmd_lst);
	temp = (char **)malloc(sizeof(char *) * (size + 2));
	if (!temp)
		return (0);
	while (i < size)
	{
		temp[i] = (*cmd_lst)->args[i];
		i++;
	}
	temp[size] = arg;
	temp[size + 1] = NULL;
	free((*cmd_lst)->args);
	(*cmd_lst)->args = temp;
	return (1);
}
