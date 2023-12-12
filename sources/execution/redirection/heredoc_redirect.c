/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_redirect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:07:03 by fseles            #+#    #+#             */
/*   Updated: 2023/12/12 14:07:05 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishel.h"


// write in open fd fd which will be close in the end
//usign readline write in file and add newline at the end
// write in file till eof is encounter
//return 0 if success return 1 if write fails 
//return 2 if line is null (ctrld + d)
static int write_in_temp_file(int *fd, char *eof)
{
	char *line;
	int compare;
	int size;

	line = readline("heredoc> ");
	if(line == NULL)
		return (2);
	compare = ft_strncmp(line, eof, ft_strlen(eof) + 1);
	while(compare != 0)
	{
		if(line == NULL)
			size = 0;
		else 
			size = ft_strlen(line);
		if(write(*fd, line, size) == -1 || write(*fd, "\n", 1) == -1)
			return(free(line), 1);
		free(line);
		line = NULL;
		line = readline("heredoc> ");
		if(line == NULL)
			return (2);
		compare = ft_strncmp(line, eof, ft_strlen(eof) + 1);
	}
	return(free(line), close(*fd), 0);
}

//create file in append mode, reading and writing
//will be stored in fd;
//1 if failed, 0 if good
static int create_append_file(int *fd, char *file_name)
{
	*fd = open(file_name, O_APPEND | O_RDWR | O_CREAT, 0777);
	if(*fd == -1)
		return(1);
	return(0);
}

//allocates file_name thatis combination of
//here_doc_temp and file_number
// return that file name if okkay 
//return NULL if something failed and print perrror
//freee this shit later
static char *get_real_fn(int file_index)
{
	char *number;
	char *file_name;

	number = ft_itoa(file_index);
	if(number == NULL)
	{
		perror("some malloc failed\n");
		return (NULL);
	}
	file_name = ft_strjoin("here_doc_temp", number);
	if(file_name == NULL)
	{
		perror("strjoin in get_real_fn failed\n");
		return(free(number), NULL);
	}
	free(number);
	return(file_name);
}

int heredoc_redirect(t_redirect *here_doc, int file_index, int *fd)
{
	char *eof;
	char *real_file_name; 

	eof = here_doc->file_name;
	real_file_name = get_real_fn(file_index);
	if(real_file_name == NULL)
		return (2);
	if(create_append_file(fd, real_file_name) == 1)
		return(free(real_file_name),1);
	free(real_file_name);
	if(write_in_temp_file(fd, eof) != 0)
		return(1);
	// if(dup2(*fd, STDIN_FILENO) == -1)
	// 	return (1);
	return(0);
}