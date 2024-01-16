#include "../../headers/minishel.h"

// t_args *make_arg_node(char *arg, int flag)
// {
// 	t_args *new_node;

// 	new_node = malloc(sizeof(t_args));
// 	if (!new_node)
// 		return (NULL);
// 	new_node->arg = arg;
// 	new_node->flag = flag;
// 	return (new_node);
// }

// void	add_arg_node(t_redirect **lst, t_redirect *new_lst)
// {
// 	t_redirect	*last_element;

// 	if (lst != NULL)
// 	{
// 		if (*lst != NULL)
// 		{
// 			last_element = *lst;
// 			while (last_element->next)
// 				last_element = last_element->next;
// 			last_element->next = new_lst;
// 		}
// 		else
// 		{
// 			*lst = new_lst;
// 		}
// 	}
// }

// int	rm_quotes_arg(char **arg)
// {
// 	char *temp;

// 	temp = ft_strtrim(*arg, "\n");
// 	if (!temp)
// 		return (0);
// 	free(*arg);
// 	*arg = temp;
// 	return (1);
// }
