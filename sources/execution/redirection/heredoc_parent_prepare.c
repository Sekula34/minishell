#include "../../../headers/minishel.h"

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
		perror("Malloc in get_real_fn failed\n");
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

static int heredoc_swap(t_redirect *here_doc, int *file_index)
{
	here_doc->eof = here_doc->file_name;
	here_doc->file_name = NULL;

	here_doc->file_name = get_real_fn(*file_index);
	*file_index = *file_index + 1;
	if(here_doc->file_name == NULL)
		return (EXIT_FAILURE);
	return(EXIT_SUCCESS);
}

static int find_all_heredoc(t_redirect *redirect, int *file_index)
{
	if(redirect == NULL)
		return(EXIT_SUCCESS);
	while(redirect != NULL)
	{
		if(redirect->type == 'h')
		{
			if(heredoc_swap(redirect, file_index) != 0)
				return(EXIT_FAILURE);
		}
		redirect = redirect->next;
	}
	return(EXIT_SUCCESS);
}

int heredoc_parent_prepare(t_cmd *cmd)
{
	static int file_index = 0;
	if(cmd == NULL)
		return (EXIT_SUCCESS);
	while(cmd != NULL)
	{
		if(cmd->redirect_lst != NULL)
		{
			if(find_all_heredoc(cmd->redirect_lst, &file_index) != 0)
				return(EXIT_FAILURE);
		}
		cmd = cmd->next;
	}
	return(EXIT_SUCCESS);
}