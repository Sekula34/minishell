/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_maker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:51:35 by fseles            #+#    #+#             */
/*   Updated: 2023/12/09 12:51:37 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishel.h"

//allocates and set all int** to be NULL
//array will be int ** and look like (NULL, NULL, NULL, NULL)
//number of nulls is 4 in this case (Last need to stay null);
static int set_and_null_pipe_arr(int ***pipe_arr, int number_of_nulls)
{
	int	i;
	
	i = 0;
	*pipe_arr = malloc(sizeof(int *) * number_of_nulls);
	if(*pipe_arr == NULL)
	{
		ft_putstr_fd("Malloc in set_and_null_failed\n", 2);
		return(EXIT_FAILURE);
	}
	while(i < number_of_nulls)
	{
		(*pipe_arr)[i] = NULL;
		i++;
	}
	return(EXIT_SUCCESS);
}

//allocates int * with two elements
//make that int * to be pipe 
//if something failes return exit_fail
//if everything is oke return succes
static int create_one_pipe(int **my_pipe)
{
	int pipe_func_value;

	*my_pipe = malloc(sizeof(int) * 2);
	if(*my_pipe == NULL)
	{
		perror("malloc in create one pipe failed\n");
		return(EXIT_FAILURE);
	}
	pipe_func_value = pipe(*my_pipe);
	if(pipe_func_value != 0)
	{
		free(*my_pipe);
		perror("pipe function in create one pipe failed\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

//puts pipe in arrray
//reutnr exfail if something fails
//return exxit succes if ok
static int put_pipes_in_array(int ***pipe_arr, int number_of_pipes)
{
	int i;
	int *pipe;

	i = 0;
	while(i < number_of_pipes)
	{
		if(create_one_pipe(&pipe) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		(*pipe_arr)[i] = pipe;
		pipe = NULL;
		i++;
	}
	return (EXIT_SUCCESS);
}

//frees all memmory of pipes_array
void clear_pipe_array(int ***pipe_arr)
{
	int i;
	i = 0;
	int *to_delete;
	while((*pipe_arr)[i] != NULL)
	{
		to_delete = (*pipe_arr)[i];
		free(to_delete);
		i++;
	}
	free(*pipe_arr);
}

//function that takes int*** to set to be pipe_arr, an number of pipes
//number of pipes should NOT include the NULL for last pipe, so if you need 2 pipes 
//you put 2 in number of pipes but array will be (pipe0, pipe1, NULL)
//retunr 1 (exit_failutre) if something fails 
//return 0(exit suceess) if everything is ok
int make_pipes(int ***pipe_arr, int number_of_pipes)
{
	int i;
	i = 0;
	if(set_and_null_pipe_arr(pipe_arr, number_of_pipes + 1) == 1)
		return (EXIT_FAILURE);
	if(put_pipes_in_array(pipe_arr, number_of_pipes) == EXIT_FAILURE)
	{
		clear_pipe_array(pipe_arr);
		return(EXIT_FAILURE);
	}
	return(EXIT_SUCCESS);
}
