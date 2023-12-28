#include "../../../headers/minishel.h"


static int prepare_input(int red_in, int input_pipe)
{
	if(red_in != 0)
	{
		if(input_pipe != 0)
			close(input_pipe);
		return(EXIT_SUCCESS);
	}
	else
	{
		if(input_pipe == 0)
			return(EXIT_SUCCESS);
		if(dup2(input_pipe, STDIN_FILENO) == -1)
		{
			perror("dup2 in prepare input failed\n");
			return(EXIT_FAILURE);
		}
		close(input_pipe);
	}
	return(EXIT_SUCCESS);
}

static int prepare_output(int red_out, int output_pipe)
{
	if(red_out != 1)
	{
		if(output_pipe != 1)
			close(output_pipe);
		return(EXIT_SUCCESS);
	}
	else
	{
		if(output_pipe == 1)
			return(EXIT_SUCCESS);
		if(dup2(output_pipe, STDOUT_FILENO) == -1)
		{
			perror("dup2 in prepare output failed\n");
			return(EXIT_FAILURE);
		}
		close(output_pipe);
	}
	return(EXIT_SUCCESS);
}

//function that take care of redirection and pipes
//inputfile is usually pipe on reading end
//output file is usually pipe on writing end
//if input file is 0 that means this is first command and function will not close that file(std)
//if output file is 1 that means this is last command and function will not close that file(std)
//close everything in pipe arr at the end
//0 ok 
//1 fail and perror is set
int prepare_fds(t_cmd *cmd, t_shell *shell, int input_file, int output_file)
{
	int red_in;
	int red_out;

	red_in = STDIN_FILENO;
	red_out = STDOUT_FILENO;
	if(redirect_handler(cmd->redirect_lst, &red_in, &red_out) != 0)
	{
		close_all_pipes(shell->pipe_arr);
		return (EXIT_FAILURE);
	}
	if(prepare_input(red_in, input_file) != 0)
	{
		close_all_pipes(shell->pipe_arr);
		return(EXIT_FAILURE);
	}
	if(prepare_output(red_out, output_file) != 0)
	{
		close_all_pipes(shell->pipe_arr);
		return(EXIT_FAILURE);
	}
	close_all_pipes(shell->pipe_arr);
	return(EXIT_SUCCESS);
}
