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
	t_vars *ex_head, *env_head;
	ex_head = NULL;
	env_head = NULL;
	if(argc && argv && envp)
		printf("Started\n");
	if(env_list_init(&ex_head, envp) != 1)
	{
		shexit(&ex_head, &env_head, -1);
	}
	if(env_list_init(&env_head, envp) != 1)
	{
		shexit(&ex_head, &env_head, -1);
	}
	pwd(&ex_head, &env_head);
	unset("HOME", &env_head, &ex_head);
	cd(NULL, &ex_head, &env_head);
	pwd(&ex_head, &env_head);
	shexit(&ex_head, &env_head, 0);
}
