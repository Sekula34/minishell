/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_redirect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:13:38 by fseles            #+#    #+#             */
/*   Updated: 2023/12/11 19:13:40 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishel.h"

//creates and store file in filedescriptor new_fd
//does not allocate
//return 1 if failes open
//return 0 if ok
//file is creted in rdwrite mode
static int create_file(int *new_fd, char *file_name)
{
	*new_fd = open(file_name, O_RDWR | O_CREAT, 0644);
	if(*new_fd == -1)
	{
		perror("Open in create file failed\n");
		return (1);
	}
	return (0);
}
//function that check if file exist
//if file does exist check if file have write premission
//if you have write permision owerwrite file
//if file does not have write permmison perror Permision denied
//if file does not exis create it wit rw-r--r-- mode
//return 0 on success
//return 1 if no permision
//retunr 2 if open fails 
static int file_checker(char *file_name, int *new_fd)
{
	int		access_val;
	access_val = access(file_name, F_OK);
	if(access_val == -1)
	{
		if(create_file(new_fd, file_name) == 1)
		{
			puts("in if");
			return(2);
		}
		puts("Here");
		return (0);
	}
	access_val = access(file_name, W_OK);
	if(access_val == -1)
	{
		perror("File checker\n");
		return (1);
	}
	*new_fd = open(file_name, O_TRUNC | O_RDWR);
	printf("%d\n", *new_fd);
	if(*new_fd == -1)
		return(2);
	return(0);
}
//return 0 on success 
//return 1 if no such file or dir
//retunr 2 if open failed
//in fd is now standard input
//fd is not allocated here
int output_redirect(t_redirect *output, int *fd)
{
	int result;

	result = file_checker(output->file_name, fd);
	if(result != 0)
		return (1);
	printf("%d\n", *fd);
	if(dup2(*fd, STDOUT_FILENO) == -1)
	{
		perror("Dup2 in input redirect failed\n");
		return (1);
	}
	printf("Bullshit");
	close(*fd);
	return(0);
}

