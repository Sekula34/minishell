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
	//char *command[] = {"wc", "-l", NULL}; // Replace "file.txt" with the name of the file you want to count lines for

	t_shell shell;
	t_cmd cd;
	// cd.args= (char *[]){"~", NULL};
	 cd.args= (char *[]){"16",NULL};


	if(shell_init(&shell, envp) == 1)
	{
		clear_list_env(&shell.head_env);
		clear_list_env(&shell.head_ex);
		return (EXIT_FAILURE);

	}
	//int status = env_exec(&shell, &cd);
	int status = shexit_exec(&shell, &cd);
	//status = cd_exec(&shell, &cd);
	//status = pwd_exec(&shell, &cd);
	//pwd(&shell.head_ex, &shell.head_env);
	//export(NULL, &shell.head_ex, &shell.head_env);
	clear_list_env(&shell.head_env);
	clear_list_env(&shell.head_ex);
	return (status);
} 
