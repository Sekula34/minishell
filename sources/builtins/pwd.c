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

//allocates print and then frees working directory
//return 0 if everything is ok
//return errno if calloc fails either right away
//or in helper function
int	pwd(void)
{
	char	*working_directory;
	int		value;

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
	free(working_directory);
	return (0);
}
