/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:39:09 by fseles            #+#    #+#             */
/*   Updated: 2023/12/05 14:39:11 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

//creates element with key and value that are allocated here
//return new element if ok
//return NULL if fails,
static t_vars	*create_alloc_elem(char *key, char *value)
{
	t_vars	*new_elem;
	char	*value_cpy;

	new_elem = create_element_key_only(key);
	if (new_elem == NULL)
		return (NULL);
	if (value == NULL)
	{
		new_elem->value = NULL;
		return (new_elem);
	}
	value_cpy = ft_strdup(value);
	if (value_cpy == NULL)
	{
		delete_element(&new_elem);
		return (NULL);
	}
	new_elem->value = value_cpy;
	return (new_elem);
}

//creates and adds two identiacal elements in both list
//key, and value will be allocated here
//return -1 if fails or 0 if ok
int	create_add_new_elems(char *key, char *value, t_vars **ex, t_vars **env)
{
	t_vars	*ex_elem;
	t_vars	*env_elem;

	ex_elem = create_alloc_elem(key, value);
	if (ex_elem == NULL)
		return (-1);
	env_elem = create_alloc_elem(key, value);
	if (env_elem == NULL)
		return (delete_element(&ex_elem), -1);
	add_element_back(ex, ex_elem);
	add_element_back(env, env_elem);
	list_sort_alpha(*ex);
	return (0);
}

//does not allocate 
//return home path from ex list 
//NULL if cannot find or not set
char	*get_home_path(t_vars *ex_head)
{
	t_vars	*head_elem;

	head_elem = get_element("HOME", ex_head);
	if (head_elem == NULL)
	{
		ft_putstr_fd("Minishell: cd: HOME not set\n", 2);
		return (NULL);
	}
	if (head_elem->value != NULL)
		return (head_elem->value);
	ft_putstr_fd("Minishell: cd: HOME not set\n", 2);
	return (NULL);
}
