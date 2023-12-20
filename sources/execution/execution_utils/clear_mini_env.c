#include "../../../headers/minishel.h"

//clears char ** and set it to NULL at the end
void clear_mini_env(char ***env_arr)
{
	int i; 

	i = 0;
	if(*env_arr == NULL)
		return ;
	while ((*env_arr)[i] != NULL)
	{
		free((*env_arr)[i]);
		i++;
	}
	free(*env_arr);
	*env_arr = NULL;
	return ;
}
