/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:21:32 by fseles            #+#    #+#             */
/*   Updated: 2023/12/11 16:21:34 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishel.h"


//function that check if file exist and it is readable
//return 1 if file does not exist or it is not readable
//print perror in that case 
//open files and set new_fd to be new filedescritport
//return 2 if open fails and print perror in that case
//return 0 on success
static int file_checker(char *file_name, int *new_fd)
{
	int		access_val;

	access_val = access(file_name, F_OK | R_OK);
	if(access_val == -1)
	{
		perror("file_checker:");
		return(1);
	}
	*new_fd = open(file_name, O_RDONLY);
	if(*new_fd == -1)
	{
		perror("Open in input redirect failed\n");
		return (2);
	}
	return (0);
}

//return 0 on success 
//return 1 if no such file or dir
//retunr 2 if open failed
//in fd is now standard input
//fd is not allocated here
int input_redirect(t_redirect *input, int *fd)
{
	int result;

	result = file_checker(input->file_name, fd);
	if(result != 0)
		return (1);
	if(dup2(*fd, STDIN_FILENO) == -1)
	{
		perror("Dup2 in input redirect failed\n");
		return (1);
	}
	close(*fd);
	return(0);

}
