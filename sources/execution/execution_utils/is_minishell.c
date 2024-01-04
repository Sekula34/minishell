//header

#include "../../../headers/minishel.h"

//checks if cmd is minishell
//if it is return 1 
//if it is not return 0
int is_minishell(t_cmd  *mini)
{
	int result;

	if(mini == NULL)
		return (0);
	result = ft_strncmp(mini->cmd, "minishell", 10);
	if(result == 0)
		return (1);
	return (0);		
}