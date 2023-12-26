#include "../../../headers/minishel.h"

//dup2 either pipe or custom file that is return afrer redirecthandler
//0 ok
//1 fail
static int set_output_file(int *new_out, int *output_pipe)
{
	if(*new_out != -1)
	{
		// if(dup2(*new_out, STDOUT_FILENO) == -1)
		// {
		// 	perror("dup2 in set output file failed\n");
		// 	return(EXIT_FAILURE);
		// }
		return(EXIT_SUCCESS);
	}
	if(dup2(*output_pipe, STDOUT_FILENO) == -1)
	{
		perror("second dup2 in set output file failed\n");
		return(EXIT_FAILURE);
	}
	return(EXIT_SUCCESS);
}

//dup2 either pipe or custom file that is return afrer redirecthandler
//0 ok
//1 fail
static int set_input_file(int *new_in, int *input_pipe)
{
	if(*new_in != -1)
	{
		// if(dup2(*new_in, STDIN_FILENO) == -1)
		// {
		// 	perror("dup2 in set input file failed\n");
		// 	return(EXIT_FAILURE);
		// }
		return(EXIT_SUCCESS);
	}
	if(dup2(*input_pipe, STDIN_FILENO) == -1)
	{
		perror("Second dup2 in set input file failed\n");
		return(EXIT_FAILURE);
	}
	return(EXIT_SUCCESS);
}

//set intput and output file accordingly
//return 0 if ok 
//return 1 if fail
//after this function stdin and stdout are either new_in and new_out
//or pipes
int set_input_output_file(int *new_in, int *new_out, int *input_pipe, int *output_pipe)
{
	if(set_input_file(new_in, input_pipe) != 0)
		return (EXIT_FAILURE);
	if(set_output_file(new_out, output_pipe) != 0)
		return (EXIT_FAILURE);
	return(EXIT_SUCCESS);
}