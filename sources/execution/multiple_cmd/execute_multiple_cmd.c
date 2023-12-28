#include "../../../headers/minishel.h"

//this is parent action 
//wait for number of kids
//and close pipesaswell
static void child_waiter(int number_of_kids, int **pipe_arr)
{
	int i;
	i = 0;

	close_all_pipes(pipe_arr);
	while (i < number_of_kids)
	{
		wait(NULL);
		i++;
	}
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
	exit(EXIT_FAILURE);
	
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
			return(child_waiter(i, shell->pipe_arr),EXIT_FAILURE);
		}
		if(id == 0)
			child_handler(shell, i, shell->pipe_arr, noc);
		shell->cmd_lst = shell->cmd_lst->next;
		i++;
	}
	child_waiter(noc, shell->pipe_arr);
	return(EXIT_SUCCESS);
}

