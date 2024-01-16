#include "../../../headers/minishel.h"

void close_all_pipes(int **pipe_arr)
{
	int i;

	i = 0;
	if(pipe_arr == NULL)
		return ;
	while(pipe_arr[i] != NULL)
	{
		close(pipe_arr[i][0]);
		close(pipe_arr[i][1]);
		i++;
	}
	return ;
}