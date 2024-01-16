/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_maker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:43:06 by fseles            #+#    #+#             */
/*   Updated: 2023/12/09 17:43:08 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishel.h"

void error_child_waiter(int number_of_kids_to_wait)
{
	int i = 0;
	while (i < number_of_kids_to_wait)
	{
		wait(NULL);
		i ++;
	}

}

int make_one_child(pid_t *child_id, int child_index)
{
	*child_id = fork();
	if(child_id == -1)
	{
		perror("There was not enough love child is not created\n");
		error_child_waiter(child_index);
		return(EXIT_FAILURE);
	}
	if(child_id == 0)
	{
		//dijete
	}
	return(EXIT_SUCCESS);

}

int child_maker(t_shell shell, int cmd_count, int **pipe_arr)
{
	int i;
	pid_t child_id;
	i = 0;

	while(i < cmd_count)
	{
		if(make_one_child(&child_id, i) == EXIT_FAILURE)
			return(EXIT_FAILURE);
		i++;
	}
	
}