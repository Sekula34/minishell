#include "../../headers/minishel.h"

t_cmd *make_cmd_node(char *cmd, t_redirect *redirect_lst, t_cmd *cmd_lst)
{
	t_cmd	*new_node;

	new_node = malloc(sizeof(t_cmd));
	if (!new_node)
		return (NULL);
	new_node->cmd = cmd;
	new_node->args = NULL;
	new_node->redirect_lst = redirect_lst;
	new_node->next = NULL;
	return (new_node);
}

void add_cmd_node(t_cmd **lst, t_cmd *new_lst)
{
	t_cmd *last_element;

	if (lst != NULL)
	{
		if (*lst != NULL)
		{
			last_element = *lst;
			while (last_element->next)
				last_element = last_element->next;
			last_element->next = new_lst;
		}
		else
		{
			*lst = new_lst;
		}
	}
}