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
	t_cmd cd;
	shell.cmd_lst = &cd;
	// cd.args= (char *[]){"~", NULL};
	cd.args= (char *[]){"/nfs/homes/fseles/eval",NULL};
	cd.cmd ="cat";
	// t_redirect redirect;
	// t_redirect output;

	// output.file_name = "output.txt";
	// output.type = 'o';
	// output.next = NULL;

	// redirect.file_name = "input.txt";
	// redirect.type = 'i';
	// redirect.next = &output;
	// redirect.to_delete = 0;
	cd.redirect_lst = NULL;
	cd.next = NULL;


	if(shell_init(&shell, envp) == 1)
	{
		clear_list_env(&shell.head_env);
		clear_list_env(&shell.head_ex);
		clear_mini_env(&shell.mini_env);
		free(shell.minishell_exec);
		return (EXIT_FAILURE);

	}
	if(execute_all_cmds(shell) != 0)
	{
		clear_list_env(&shell.head_env);
		clear_list_env(&shell.head_ex);
		clear_mini_env(&shell.mini_env);
		free(shell.minishell_exec);
		free(cd.path);
		return (EXIT_FAILURE);
	}
	
	printf("printf printa gdje \n");
	// printf("Minishell path is %s\n", shell.minishell_exec);
	// char **mini_arr;
	// mini_arr = NULL;
	// if(set_mini_env(&mini_arr, shell.head_env)==1)
	// {
	// 	clear_list_env(&shell.head_env);
	// 	clear_list_env(&shell.head_ex);
	// 	free(shell.minishell_exec);
	// 	return (EXIT_FAILURE);
	// }

	// printf("A jesi lud\n");
	// char *linija;
	// linija = readline("promopt : ");
	// rl_on_new_line_with_prompt();
	// if(*linija == '1')
	// 	execute_minishell(&shell);
	// free(linija);
	// int i = 0;
	// while(mini_arr[i] != NULL)
	// {
	// 	printf("Line %d is : %s\n",i, mini_arr[i]);
	// 	i++;
	// }
	// one_command_exec(&cd, &shell);
	// pwd(&shell.head_ex, &shell.head_env);
	// //int status = env_exec(&shell, &cd);
	// int status = 0;

	// unset_exec(&shell, &cd);
	//env(shell.head_env);
	//status = cd_exec(&shell, &cd);
	//status = pwd_exec(&shell, &cd);
	//pwd(&shell.head_ex, &shell.head_env);
	//export(NULL, &shell.head_ex, &shell.head_env);
	clear_list_env(&shell.head_env);
	clear_list_env(&shell.head_ex);
	free(cd.path);
	clear_mini_env(&shell.mini_env);
	free(shell.minishell_exec);
	return (0);
} 
