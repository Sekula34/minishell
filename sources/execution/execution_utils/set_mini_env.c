
#include "../../../headers/minishel.h"

//connct key and value in one string in format 
//SHELL=/bin/bash
//print perror and 1 if failed
//0 ok
static int set_one_line(char **line, t_vars *element)
{
	char *temp;

	*line = ft_strjoin(element->key, "=");
	if(*line == NULL)
	{
		perror("set_one_line failed1\n");
		return (EXIT_FAILURE);
	}
	if(element->value == NULL)
		return (EXIT_SUCCESS);
	temp = *line;
	*line = NULL;
	*line = ft_strjoin(temp, element->value);
	if(*line == NULL)
	{
		free(temp);
		perror("set_one_line failed2\n");
		return(EXIT_FAILURE);
	}
	free(temp);
	return(EXIT_SUCCESS);
}

//goes throug head_env and set all char ***
//0 ok 1 fail
static int set_all_lines(char ***arr_env, t_vars *head_env)
{
	char *line;
	int i;

	i = 0;
	while(head_env != NULL)
	{
		if(set_one_line(&line, head_env) == 1)
			return (EXIT_FAILURE);
		(*arr_env)[i] = line;
		line = NULL;
		i++;
		head_env = head_env->next;
	}
	return(EXIT_SUCCESS);
}

//goes through all head_env elemetnts and turn them in format
//KEY=VALUE;
//adds all string in char **;
//return 0 if good
//return 1 bad and clears all env_arr;
int set_mini_env(char ***env_arr, t_vars *head_env)
{
	int list_elements;

	clear_mini_env(env_arr);
	list_elements = count_list_elements(head_env);
	*env_arr = ft_calloc(list_elements + 1, sizeof(char *));
	if(*env_arr == NULL)
	{
		perror("Set mini env :\n");
		return (EXIT_FAILURE);
	}
	if(set_all_lines(env_arr, head_env) == 1)
	{
		clear_mini_env(env_arr);
		return(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
