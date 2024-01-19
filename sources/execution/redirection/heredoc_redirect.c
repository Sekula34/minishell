/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_redirect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:07:03 by fseles            #+#    #+#             */
/*   Updated: 2024/01/17 16:39:49 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishel.h"

//delete temporary heredoc_file;
void here_doc_file_delete(t_redirect *heredoc)
{
	if(heredoc->file_name != NULL)
	{
		if(unlink(heredoc->file_name) != 0)
			perror("unlink in here_doc_clear failed\n");
		free(heredoc->file_name);
		heredoc->file_name = NULL;
	}
}

// write in open fd fd which will be close in the end
//usign readline write in file and add newline at the end
// write in file till eof is encounter
//return 0 if success return 1 if write fails 
//return 2 if line is null (ctrld + d)
static int write_in_temp_file(int *fd, char *eof, t_shell *shell)
{
	char *line;
	int compare;
	int size;
	char *final_line;

	minishel_signals(4);

	line = readline("heredoc> ");
	if(line == NULL)
	{
		perror("heredoc:");
		return (close(*fd), EXIT_SUCCESS);
	}
	compare = ft_strncmp(line, eof, ft_strlen(eof) + 1);
	while(compare != 0)
	{
		if(line == NULL)
		{
			//perror("heeredoc 2:");
			size = 0;
			return(EXIT_SUCCESS);
		}
		else 
			size = ft_strlen(line);
		if (heredoc_expand(shell, line, &final_line) != 1)
		{
			return(free(line), close(*fd), 1);
		}
		size = ft_strlen(final_line);
		if(write(*fd, final_line, size) == -1 || write(*fd, "\n", 1) == -1)
			return(free(line), free(final_line), close(*fd), 1);
		free(line);
		free(final_line);
		line = NULL;
		line = readline("heredoc> ");
		if(line == NULL)
		{
			//perror("heeredoc 2:");
			size = 0;
			return(EXIT_SUCCESS);
		}
			//return (close(*fd), 2);
		compare = ft_strncmp(line, eof, ft_strlen(eof) + 1);
	}
	return(free(line),close(*fd),0);
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
// static char *get_real_fn(int file_index)
// {
// 	char *number;
// 	char *file_name;

// 	number = ft_itoa(file_index);
// 	if(number == NULL)
// 	{
// 		perror("Malloc in get_real_fn failed\n");
// 		return (NULL);
// 	}
// 	file_name = ft_strjoin("here_doc_temp", number);
// 	if(file_name == NULL)
// 	{
// 		perror("strjoin in get_real_fn failed\n");
// 		return(free(number), NULL);
// 	}
// 	free(number);
// 	return(file_name);
// }

//function that creates and write in temp_heredoc_file
//0 ok
//1 fail
int heredoc_redirect(t_redirect *here_doc, int *fd, t_shell *shell)
{
	// here_doc->eof = here_doc->file_name;
	// here_doc->file_name = NULL;

	// here_doc->file_name = get_real_fn(file_index);
	// if(here_doc->file_name == NULL)
	// 	return (EXIT_FAILURE);
	if(create_append_file(fd, here_doc->file_name) != 0)
		return(EXIT_FAILURE);
	here_doc->to_delete = 1;
	if(write_in_temp_file(fd, here_doc->eof, shell) != 0)
		return(EXIT_FAILURE);
	// if (input_redirect(here_doc, fd) !=0)
	// 	return(EXIT_FAILURE);
	return(EXIT_SUCCESS);
}
