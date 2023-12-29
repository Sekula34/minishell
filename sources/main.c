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
	t_cmd cmd;
	t_cmd cmd2;
	// cd.args= (char *[]){"~", NULL};

	t_redirect redirect2;
	redirect2.file_name ="kraj";
	redirect2.type ='h';
	redirect2.next = NULL;


	cmd.args= (char *[]){"cat command",NULL};
	cmd.cmd ="cat";
	cmd.redirect_lst = &redirect2;
	cmd.next = NULL;;
	cmd.path = NULL;

	cmd2.args = (char *[]){"wc command",NULL};
	cmd2.cmd = "wc";
	cmd2.next = NULL;
	cmd2.redirect_lst = &redirect2;
	shell.cmd_lst = &cmd;
	cmd2.path = NULL;
	(void )cmd2;

	if(shell_init(&shell, envp) == 1)
	{
		clear_list_env(&shell.head_env);
		clear_list_env(&shell.head_ex);
		clear_mini_env(&shell.mini_env);
		free(shell.minishell_exec);
		return (EXIT_FAILURE);

	}
	//child_multi_exec(&cmd, &shell, 0, 1);
	if(execute_all_cmds(&shell) != 0)
	{
		clear_list_env(&shell.head_env);
		clear_list_env(&shell.head_ex);
		clear_mini_env(&shell.mini_env);
		free(shell.minishell_exec);
		free(cmd.path);
		return (EXIT_FAILURE);
	}
	
	printf("printf printa gdje \n");
	clear_list_env(&shell.head_env);
	clear_list_env(&shell.head_ex);
	clear_mini_env(&shell.mini_env);
	free(cmd.path);
	free(cmd2.path);
	clear_pipe_array(&shell.pipe_arr);
	free(shell.minishell_exec);
	here_doc_file_delete(&redirect2);
	free(redirect2.file_name);
	return (0);
} 
