#include "../../headers/minishel.h"

t_redirect	*make_redirect_node(char type, char *file_name)
{
	t_redirect	*new_node;

	new_node = malloc(sizeof(t_redirect));
	if (!new_node)
		return (NULL);
	new_node->type = type;
	new_node->file_name = file_name;
	new_node->del_flag = 0;
	new_node->next = NULL;
	return (new_node);
}

void	add_redirect_node(t_redirect **lst, t_redirect *new_lst)
{
	t_redirect	*last_element;

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

/* t_redirect	*end_of_redirect(t_redirect *lst)
{
	if (lst)
	{
		while (lst->next != NULL)
			lst = lst->next;
		return (lst);
	}
	return (NULL);
} */