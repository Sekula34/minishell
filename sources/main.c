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
	char *command[] = {"wc", "-l", NULL}; // Replace "file.txt" with the name of the file you want to count lines for

	int input;
	int output;
	t_redirect firs_red;
	firs_red.type = 'i';
	firs_red.file_name = "input.txt";
	t_redirect second_red;
	second_red.type ='o';
	second_red.file_name ="output.txt";
	firs_red.next = &second_red;
	second_red.next = NULL;
	if(redirect_handler(&firs_red, &input, &output) != 0)
		return(EXIT_FAILURE);
	printf("Ajde printaj sad ovo u picku materinu\n");
    if (execve("/usr/bin/wc", command, NULL) == -1) {
        perror("execve");
        exit(EXIT_FAILURE);
    }
	return(EXIT_SUCCESS);
} 
