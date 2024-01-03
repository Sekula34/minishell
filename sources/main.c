/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:44:01 by fseles            #+#    #+#             */
/*   Updated: 2023/12/05 17:46:28 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishel.h"

int	main(int argc, char **argv, char **envp)
{
	if(argc && argv && envp)
	{

	}
	t_shell shell;
	t_cmd *cmd;
	cmd = malloc(sizeof(t_cmd));
	if(cmd == NULL)
		return (EXIT_FAILURE);
	t_cmd *cmd2;
	// cd.args= (char *[]){"~", NULL};
	cmd2 = malloc(sizeof(t_cmd));

	t_redirect *redirect2;
	redirect2 = malloc(sizeof(t_redirect));
	redirect2->file_name = ft_strdup("kraj");
	redirect2->type ='h';
	redirect2->next = NULL;


	cmd->args= (char *[]){"ls",NULL};
	// cmd->args = malloc(sizeof(char *));
	// cmd->args[0] = ft_strdup("ls");
	cmd->cmd = ft_strdup("ls");
	cmd->redirect_lst = redirect2;
	cmd->next =  cmd2;
	cmd->path = NULL;
	shell.cmd_lst = cmd;
	shell.first_cmd_copy = cmd;

	cmd2->args = (char *[]){"wc command",NULL};
	cmd2->cmd = ft_strdup("wc");
	cmd2->next = NULL;
	cmd2->redirect_lst = NULL;
	cmd2->path = NULL;
	(void )cmd2;
	heredoc_parent_prepare(cmd);
	if(shell_init(&shell, envp) == 1)
	{
		shell_clear(&shell);
		return (EXIT_FAILURE);

	}
	if(execute_all_cmds(&shell) != 0)
	{
		// clear_list_env(&shell.head_env);
		// clear_list_env(&shell.head_ex);
		// clear_mini_env(&shell.mini_env);
		// free(shell.minishell_exec);
		// free(cmd.path);
		shell_clear(&shell);
		return (EXIT_FAILURE);
	}
	
	// printf("printf printa gdje \n");
	// t_vars *element;
	// element = get_element("?", shell.head_env);
	// printf("%s\n", element->value);
	// clear_list_env(&shell.head_env);
	// clear_list_env(&shell.head_ex);
	// clear_mini_env(&shell.mini_env);
	// free(cmd.path);
	// free(cmd2.path);
	// clear_pipe_array(&shell.pipe_arr);
	// free(shell.minishell_exec);
	//here_doc_file_delete(&redirect2);
	//free(redirect2.file_name);
	//shell.cmd_lst = cmd;
	shell_clear(&shell);
	return (0);
} 
