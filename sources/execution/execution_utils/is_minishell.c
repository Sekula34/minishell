/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 13:26:03 by fseles            #+#    #+#             */
/*   Updated: 2024/01/20 13:26:05 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishel.h"

//checks if cmd is minishell
//if it is return 1 
//if it is not return 0
int	is_minishell(t_cmd *mini)
{
	int	result;

	if (mini == NULL)
		return (0);
	result = ft_strncmp(mini->cmd, "minishell", 10);
	if (result == 0)
		return (1);
	return (0);
}
