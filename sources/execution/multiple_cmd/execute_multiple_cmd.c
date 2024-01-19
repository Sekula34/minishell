#include "../../../headers/minishel.h"

//this is parent action 
//wait for number of kids
//and close pipesaswell
static void child_waiter(int number_of_kids, int **pipe_arr, t_shell *shell)
{
	int i;
	int status;
	int exit_status;
	i = 0;
	close_all_pipes(pipe_arr);
	while (i < number_of_kids)
	{
		waitpid(-1, &status, 0);
		if(WIFEXITED(status))
		{
			exit_status = WEXITSTATUS(status);
			//ft_printf("exit status of child is %d\n", exit_status);
		}
		//ft_printf("status returned to parent is %d\n", status);
		//wait(NULL);
		i++;
	}
	export_exit_status(exit_status, shell);
}


static void child_handler(t_shell *shell, int index, int **pipe_arr, int number_of_kids)
{

	
	if(index == 0)
	{
		child_multi_exec(shell->cmd_lst, shell, 0, pipe_arr[0][1]);
	}
	else if(index + 1 == number_of_kids)
	{
		child_multi_exec(shell->cmd_lst, shell, pipe_arr[index - 1][0], 1);
	}
	else
		child_multi_exec(shell->cmd_lst, shell, pipe_arr[index - 1][0], pipe_arr[index][1]);
	//ft_printf("special case called\n");
	shexit(shell, 0);
}

int execute_multiple_cmd(int noc, t_shell *shell)
{
	int i;
	pid_t id;

	i = 0;
	shell->pipe_arr = NULL;
	if(make_pipes(&shell->pipe_arr, noc - 1) != 0)
		return(EXIT_FAILURE);
	while(i < noc)
	{
		id = fork();
		if(id == -1)
		{
			perror("fork in execute multiple cmd failed\n");
			return(child_waiter(i, shell->pipe_arr, shell),EXIT_FAILURE);
		}
		if(id == 0)
			child_handler(shell, i, shell->pipe_arr, noc);
		shell->cmd_lst = shell->cmd_lst->next;
		i++;
	}
	child_waiter(noc, shell->pipe_arr, shell);
	clear_pipe_array(&shell->pipe_arr);
	//ft_printf("Pipe array is %p\n", shell->pipe_arr);
	return(EXIT_SUCCESS);
}

