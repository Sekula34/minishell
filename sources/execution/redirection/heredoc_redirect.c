/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_redirect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:07:03 by fseles            #+#    #+#             */
/*   Updated: 2024/01/21 19:44:43 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishel.h"

static void	freeing_lines(char **line, char **final_line)
{
	if (*line)
	{
		free(*line);
		*line = NULL;
	}
	if (*final_line)
	{
		free(*final_line);
		*final_line = NULL;
	}
}

int	first_read(char **line, int *fd)
{
	minishel_signals(4);
	*line = readline("heredoc> ");
	if (*line == NULL || g_signal != 0)
	{
		close(*fd);
		free(*line);
		if (g_signal == 0)
			return (0);
		return (g_signal);
	}
	return (0);
}

// write in open fd fd which will be close in the end
//usign readline write in file and add newline at the end
// write in file till eof is encounter
//return 0 if success return 1 if write fails 
//return 2 if line is null (ctrld + d)
static int	write_in_temp_file(int *fd, char *eof, t_shell *shell)
{
	char	*line;
	int		compare;
	int		size;
	char	*final_line;
	int		first_read_val;

	final_line = NULL;
	first_read_val = first_read(&line, fd);
	if (first_read_val != 0)
		return (EXIT_FAILURE);
	setting_compare_var(line, eof, &compare);
	while (compare != 0 && g_signal == 0)
	{
		if (heredoc_expand(shell, line, &final_line) != 1)
			return (free(line), close(*fd), 1);
		size = ft_strlen(final_line);
		if (write(*fd, final_line, size) == -1 || write(*fd, "\n", 1) == -1)
			return (free(line), free(final_line), close(*fd), 1);
		freeing_lines(&line, &final_line);
		line = readline("heredoc> ");
		if (line == NULL || !line[0])
			break ;
		compare = ft_strncmp(line, eof, ft_strlen(eof) + 1);
	}
	return (freeing_lines(&line, &final_line), close(*fd), g_signal);
}

//create file in append mode, reading and writing
//will be stored in fd;
//1 if failed, 0 if good
static int	create_append_file(int *fd, char *file_name)
{
	*fd = open(file_name, O_APPEND | O_RDWR | O_CREAT, 0777);
	if (*fd == -1)
		return (1);
	return (0);
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
int	heredoc_redirect(t_redirect *here_doc, int *fd, t_shell *shell)
{
	if (create_append_file(fd, here_doc->file_name) != 0)
		return (EXIT_FAILURE);
	here_doc->to_delete = 1;
	if (write_in_temp_file(fd, here_doc->eof, shell) != 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
