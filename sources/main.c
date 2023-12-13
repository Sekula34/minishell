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

	if(shell_init(&shell, envp) == 1)
	{
		clear_list_env(&shell.head_env);
		clear_list_env(&shell.head_ex);
		return (EXIT_FAILURE);

	}
	export(NULL, &shell.head_ex, &shell.head_env);
	clear_list_env(&shell.head_env);
	clear_list_env(&shell.head_ex);
	return (0);
} 
