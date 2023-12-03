/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:54:03 by fseles            #+#    #+#             */
/*   Updated: 2023/11/28 13:54:04 by fseles           ###   ########.fr       */
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
//try to find pwd in export
//print pwd and return 1 if you find it, or return -1
//-1 if head is NULL or cannot find pwd key
//or value is null;
static int my_pwd(t_vars *head_ex)
{
	t_vars *pwd_element;

	if(head_ex == NULL)
		return (-1);
	pwd_element = get_element("PWD=", head_ex);
	if(pwd_element == NULL)
		return (-1);
	if(pwd_element->value == NULL)
		return (-1);
	printf("%s\n", pwd_element->value);
	return (1);
}

//return 0 if everything is ok
//-1 if error happend
//takes pwd_value which should be allocated before
//creates two PWD elemetns in both ex and env list
static int create_PWD_element(char *pwd_value, t_vars **ex, t_vars **env)
{
	t_vars *pwd_element_ex;
	t_vars *pwd_element_env;
	char *pwd_value_cpy;

	pwd_value_cpy = ft_strdup(pwd_value);
	if(pwd_value_cpy == NULL)
		return (-1);
	pwd_element_ex = create_element_key_only("PWD=");
	if(pwd_element_ex == NULL)
		return (free(pwd_value_cpy),-1);
	pwd_element_env = create_element_key_only("PWD=");
	if(pwd_element_env == NULL)
	{
		delete_element(&pwd_element_ex);
		return (free(pwd_value_cpy),-1);
	}
	pwd_element_ex->value = pwd_value;
	pwd_element_env->value = pwd_value_cpy;
	add_element_back(ex, pwd_element_ex);
	add_element_back(env, pwd_element_env);
	list_sort_alpha(*ex);
	return (0);
}

//tries to find workingdir in head_ex
//if cannot find in linked list then try official function
int	pwd(t_vars **head_ex, t_vars **head_env)
{
	char	*working_directory;
	int		value;

	if(my_pwd(*head_ex) == 1)
		return (0);
	working_directory = ft_calloc(2, sizeof(char));
	if (working_directory == NULL)
	{
		perror("Calloc in pwd failed\n");
		return (errno);
	}
	getcwd(working_directory, 2);
	value = set_wdir(&working_directory);
	if (value != 0)
		return (errno);
	printf("%s\n", working_directory);
	if(create_PWD_element(working_directory, head_ex, head_env) == -1)
		return(free(working_directory), -1);
	return (0);
}
