#include "../../headers/minishel.h"

void	clear_cmd_lst(t_cmd **head)
{
	t_cmd	*to_delete;

	while (*head != NULL)
	{
		to_delete = *head;
		*head = (*head)->next;
		delete_cmd_element(&to_delete);
	}
}

void	delete_cmd_element(t_cmd **element_to_delete)
{
	t_cmd	*delete;
	int	i;

	i = 1;
	delete = *element_to_delete;

	if (delete->path)
		free(delete->path);
	if (delete->cmd)
		free(delete->cmd);
	
	while(delete->args && delete->args[i])
	{
		free(delete->args[i]);
		i++;
	}
	free(delete->args);

	clear_redirect_lst(&delete->redirect_lst);
	
	
	free(delete);
}

void	clear_redirect_lst(t_redirect **head)
{
	t_redirect *to_delete;

	while (*head != NULL)
	{
		to_delete = *head;
		*head = (*head)->next;
		delete_redirect_element(&to_delete);
	}
}

void	delete_redirect_element(t_redirect **element_to_delete)
{
	t_redirect *delete;

	delete = *element_to_delete;

	free(delete->file_name);
	free(delete);
}

void	free_2d_arr(char ***arr)
{
	int	i;

	i = 0;
	while ((*arr)[i])
	{
		free((*arr)[i]);
		i++;
	}
	free(*arr);
}

void	parsing_free(char ***lines, char **line2, char ***tokens, char ***fin)
{
	if (*lines)
		free_2d_arr(lines);
	if (*tokens)
		free_2d_arr(tokens);
	if (*fin)
		free_2d_arr(fin);
	if (*line2)
		free(*line2);
}
