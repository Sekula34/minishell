#include "../../headers/minishel.h"

void clear_one_redirect(t_redirect **redirect)
{
	if(redirect == NULL || *redirect == NULL)
		return;
	if((*redirect)->type == 'h')
	{
		free((*redirect)->eof);
		here_doc_file_delete(*redirect);
	}
	free((*redirect)->file_name);
	free(*redirect);
}

void clear_redirects(t_redirect **list)
{
	t_redirect *to_delete;
	if(list == NULL || *list == NULL)
		return;
	while(*list != NULL)
	{
		to_delete = (*list)->next;
		clear_one_redirect(list);
		*list = to_delete;
		to_delete = NULL;
	}
}

void clear_one_command(t_cmd **cmd)
{
	if(cmd == NULL || *cmd == NULL)
		return ;
	clear_redirects(&(*cmd)->redirect_lst);
	free((*cmd)->path);
	free((*cmd)->cmd);
	//clear_mini_env(&(*cmd)->args);
	free(*cmd);
	
}

void clear_all_commands(t_cmd **cmd_list)
{
	if(cmd_list == NULL || *cmd_list == NULL)
		return ;
	t_cmd *to_delete;
	while(*cmd_list != NULL)
	{
		to_delete = (*cmd_list)->next;
		clear_one_command(cmd_list);
		*cmd_list = to_delete;
		to_delete = NULL;
	}
}

void shell_clear(t_shell *shell)
{
	clear_list_env(&shell->head_env);
	clear_list_env(&shell->head_ex);
	clear_pipe_array(&shell->pipe_arr);
	clear_mini_env(&shell->mini_env);
	free(shell->minishell_exec);
	clear_all_commands(&shell->cmd_lst);
}