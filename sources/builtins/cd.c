/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:19:49 by fseles            #+#    #+#             */
/*   Updated: 2023/11/28 16:19:50 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"



//set working directory
//helper function that allocates newspace for working dir
//while getcwd set errno to ERANGE increase by one 
//eventually in working dir is stored path
//or calloc will fail
//return errno if calloc fails, 0 if everything ok
static int	set_wdir(char **working_dir)
{
	size_t	i;

	*working_dir= ft_calloc(2, sizeof(char));
	if (*working_dir == NULL)
	{
		perror("Calloc in set_wdir failed\n");
		return (errno);
	}
	getcwd(*working_dir, 2);
	i = 3;
	while (errno == ERANGE)
	{
		errno = 0;
		free(*working_dir);
		*working_dir = NULL;
		*working_dir = ft_calloc(i, sizeof(char));
		if (*working_dir == NULL)
		{
			perror("ft_calloc in pwd (set_wdir) failed\n");
			return (errno);
		}
		getcwd(*working_dir, i);
		i++;
	}
	return (0);
}

//alocates and return current directory
//tries to find element with PWD
//if that element exitst then copy value of it with strdup an return in
//if element does not exist get current directory with official function
//return allocated path to current dir or NULL if fails
static char *get_current_dir(t_vars *ex_head)
{
	t_vars *pwd_element;
	char *current_dir;

	pwd_element = get_element("PWD", ex_head);
	if (pwd_element == NULL)
	{
		if(set_wdir(&current_dir) != 0)
			return (NULL);
		return (current_dir);
	}
	if (pwd_element->value == NULL)
		return (NULL);
	current_dir = ft_strdup(pwd_element->value);
	if (current_dir == NULL)
		return (NULL);
	return(current_dir);
}

//function that sets old_dir values for ex_head and env_head
//if OLDPWD does not exits creates one
//return -1 if fails 
//return 0 if ok
int value_setter(char *key, char *new_value, t_vars **ex_head, t_vars **env_head)
{
	t_vars *old_element_ex;
	t_vars *old_element_env;
	
	old_element_ex = get_element(key, *ex_head);
	old_element_env = get_element(key, *env_head);
	if(old_element_ex != NULL)
	{
		if(set_new_value(old_element_env, new_value) != 0)
			return (-1);
		if(set_new_value(old_element_ex, new_value) != 0)
			return (-1);
		return(0);
	}
	if(create_add_new_elems(key, new_value, ex_head, env_head) == 0)
		return (0);
	return (-1);
}

//changes directory, set oldpwd, newpwd
//return 0 on success -1 if failed
int cd(char *directory, t_vars **ex_head, t_vars **env_head)
{
	char *current;

	current = get_current_dir(*ex_head);
	if(current == NULL)
		return (-1);
	if(chdir(directory) != 0)
		return(free(current), -1);
	if(value_setter("OLDPWD", current, ex_head, env_head) == -1)
		return (free(current), -1);
	free(current);
	current = NULL;
	if(set_wdir(&current) != 0)
		return (-1);
	if(value_setter("PWD", current, ex_head, env_head) == -1)
		return(free(current), -1);
	free(current);
	return(0);
}

