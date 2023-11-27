/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:44:01 by fseles            #+#    #+#             */
/*   Updated: 2023/11/27 16:44:03 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishel.h"

int	main(int argc, char **argv, char **envp)
{
	int i = 0;
	if(argc && argv)
		printf("samo printaj");
	while(envp[i] != NULL)
	{
		printf("%s\n", envp[i]);
		i++;
	}
	ft_putstr_fd("a sad bus radio ha?", 2);
	char *line;
	line = readline("shell:");
	printf("%s\n", line);
	free(line);
}
