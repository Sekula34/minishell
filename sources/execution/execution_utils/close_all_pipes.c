/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_all_pipes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 13:35:52 by fseles            #+#    #+#             */
/*   Updated: 2024/01/20 13:35:55 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishel.h"

void	close_all_pipes(int **pipe_arr)
{
	int	i;

	i = 0;
	if (pipe_arr == NULL)
		return ;
	while (pipe_arr[i] != NULL)
	{
		close(pipe_arr[i][0]);
		close(pipe_arr[i][1]);
		i++;
	}
	return ;
}
