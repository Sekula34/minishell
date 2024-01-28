#include "../../../headers/minishel.h"

t_redirect *get_last_output(t_cmd *cmd)
{
	t_redirect *to_return;
	t_redirect *current;

	to_return = NULL;
	current = NULL;
	if(cmd == NULL)
		return NULL;
	if(cmd->redirect_lst == NULL)
		return (NULL);
	current = cmd->redirect_lst;
	while(current != NULL)
	{
		if(current->type == 'o' || current->type == 'a')
			to_return = current;
		current = current->next;
	}
	return(to_return);
}

int set_multi_output(int output_pipe, t_cmd *cmd)
{
	t_redirect *last_output;

	last_output = NULL;
	last_output = get_last_output(cmd);
	if(last_output != NULL)
	{
		cmd->out_fd = open(last_output->file_name,  O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if(cmd->out_fd == -1)
			return(perror("Set multi input fail"), 1);
		if(dup2(cmd->out_fd, STDOUT_FILENO) == -1)
			return(perror("set multi input dup failed"), 1);
		close(cmd->out_fd);
		return (0);
	}
	if(output_pipe == 1)
		return (0);
	if(dup2(output_pipe, STDOUT_FILENO) == -1)
		return(perror("dupp22 in multi input "), 1);
	return(0);

}



//goes through cmd redirect list
//return pointer to last redirect input
//or NULL if cant find input_or heredoc red
t_redirect *get_last_input(t_cmd *cmd)
{
	t_redirect *to_return;
	t_redirect *current;

	to_return = NULL;
	current = NULL;
	if(cmd == NULL)
		return NULL;
	if(cmd->redirect_lst == NULL)
		return (NULL);
	current = cmd->redirect_lst;
	while(current != NULL)
	{
		if(current->type == 'i' || current->type == 'h')
			to_return = current;
		current = current->next;
	}
	return(to_return);
}

//dup2 and close redirect input file if exist
//dup2 pipe if input does not exist
//0 ok
//1 fail ->critical
int set_multi_input(int input_pipe, t_cmd *cmd)
{
	t_redirect *last_input;

	last_input = NULL;
	last_input = get_last_input(cmd);
	if(last_input != NULL)
	{
		cmd->in_fd = open(last_input->file_name, O_RDONLY);
		if(cmd->in_fd == -1)
			return(perror("Set multi input fail"), 1);
		if(dup2(cmd->in_fd, STDIN_FILENO) == -1)
			return(perror("set multi input dup failed"), 1);
		close(cmd->in_fd);
		return (0);
	}
	if(input_pipe == 0)
		return 0;
	if(dup2(input_pipe, STDIN_FILENO) == -1)
		return(perror("dupp22 in multi input "), 1);
	return(0);

}

void multi_og(t_cmd *cmd, int input_pipe, int output_pipe, t_shell *shell)
{
	if(set_multi_input(input_pipe, cmd) != 0)
		shexit(shell, 1);
	if(set_multi_output(output_pipe, cmd) != 0)
		shexit(shell, 1);
	close_all_pipes(shell->pipe_arr);
	if (cmd == NULL)
		shexit(shell, 127);
	if (cmd->cmd == NULL)
		shexit(shell, 127);
	if (set_cmd_path(cmd, shell) != 0)
		shexit(shell, 127);
	if (cmd->path == NULL)
	{
		ft_putstr_fd("Command not found \n", 2);
		shexit(shell, 127);
	}
	child_executor(cmd, shell);
}

void multi_builtin(t_cmd *cmd, int input_pipe, int output_pipe, t_shell *shell)
{
	int builtin_num;

	if(set_multi_input(input_pipe, cmd) != 0)
		shexit(shell, 1);
	if(set_multi_output(output_pipe, cmd) != 0)
		shexit(shell, 1);
	builtin_num = is_cmd_builtin(cmd);
	execute_builtin(builtin_num, shell, cmd);
	close_all_pipes(shell->pipe_arr);
	shexit(shell, shell->last_exit_code);
}


void multi_builtin_menu(t_shell *shell, int child_index, int last_index, t_cmd *cmd)
{
	if(child_index == 0)
	{
		multi_builtin(cmd, 0, shell->pipe_arr[0][1], shell);
	}
	else if(child_index + 1 == last_index)
	{
		multi_builtin(cmd, shell->pipe_arr[child_index - 1][0], 1, shell);
	}
	else
	{
		multi_builtin(cmd, shell->pipe_arr[child_index - 1][0], shell->pipe_arr[child_index][1], shell);
	}
}
void multi_original_menu(t_shell *shell, int child_index, int last_index, t_cmd *cmd)
{
	if(child_index == 0)
	{
		multi_og(cmd, 0, shell->pipe_arr[0][1], shell);
	}
	else if(child_index + 1 == last_index)
	{
		multi_og(cmd, shell->pipe_arr[child_index - 1][0], 1, shell);
	}
	else
	{
		multi_og(cmd, shell->pipe_arr[child_index - 1][0], shell->pipe_arr[child_index][1], shell);
	}
}


void multi_child_handler(t_shell *shell, int child_index, int last_index, t_cmd *cmd)
{
	int is_builtin;

	is_builtin = is_cmd_builtin(cmd);
	if(is_builtin >=1 && is_builtin<= 7)
		multi_builtin_menu(shell, child_index, last_index, cmd);
	else 
	{
		multi_original_menu(shell, child_index, last_index, cmd);
	}
	shexit(shell, 1);
	
		//KRAJ
	//MULTI_original
		//KRAJ
}


