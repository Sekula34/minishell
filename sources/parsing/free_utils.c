#include "../../headers/minishel.h"

void	clear_cmd_lst(t_cmd **head)
{
	t_cmd	*to_delete;

	while (*head != NULL)
	{
		to_delete = *head;
		*head = (*head)->next;
		delete_element(&to_delete);
	}
}