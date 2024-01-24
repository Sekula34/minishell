/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:36:32 by wvan-der          #+#    #+#             */
/*   Updated: 2024/01/22 11:52:29 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishel.h"
#include "../headers/get_next_line.h"

// void my_signal_handle()
// {
// 	ft_printf("\n");
// 	rl_replace_line("", 0);
// 	rl_on_new_line();
// 	rl_redisplay();
// }

// void interacitve_signals()
// {
// 	signal(SIGINT, my_signal_handle);
// 	signal(SIGQUIT, SIG_IGN);
// }

int	g_signal;

//0 ok 
//-1 continue
static int	middle_part_of_code(t_shell *shell, char **line, int *pars_return)
{
	check_g_signal(shell);
	if (!*line)
	{
		shexit(shell, shell->last_exit_code);
	}
	//add_history(*line);
	if (*line && (*line)[0] == 0)
	{
		free(*line);
		return (-1);
	}
	*pars_return = parsing(shell, *line);
	if (*pars_return == 2)
	{
		if (export_exit_status(2, shell) != 0)
			shexit(shell, 1);
		free(*line);
		return (-1);
	}
	return (0);
}

void	first_part_of_code(t_shell *shell, int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	if (shell_init(shell, envp) != 0)
		shexit(shell, 1);
}

// 0 ok
// 1 fail
//-1 continue
static int	heredoc_in_main(t_shell *shell, char **line)
{
	if (heredoc_parent_prepare(shell->cmd_lst, shell) != 0)
	{
		if (g_signal != 0)
		{
			free(*line);
			clear_all_commands(&shell->first_cmd_copy);
			if (export_exit_status(g_signal + 128, shell) != 0)
				shexit(shell, 1);
			g_signal = 0;
			return (-1);
		}
		shexit(shell, 1);
	}
	return (0);
}

static void	last_part_of_code(t_shell *shell, char **line)
{
	clear_all_commands(&shell->first_cmd_copy);
	shell->first_cmd_copy = NULL;
	free(*line);
	*line = NULL;
	//rl_on_new_line();
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;
	char	*line;
	int		parsing_return;


	//int i = 0;


	first_part_of_code(&shell, argc, argv, envp);
	while (1)
	{
		minishel_signals(1);
		if (isatty(fileno(stdin)))
			line = readline("minishell: ");
		else
		{
			char *line2;
			line2 = get_next_line(fileno(stdin));
			line = ft_strtrim(line2, "\n");
			free(line2);
		}

		
		//i++;
		// line = ft_strdup("echo $$$$$ $LKJLLJ $* $USER $\"USER\" > file | cat <file");
		if (!line)
			return (shexit(&shell, shell.last_exit_code));
		// line = readline("finishell: ");

		if (middle_part_of_code(&shell, &line, &parsing_return) == -1)
			continue ;
		shell.first_cmd_copy = shell.cmd_lst;
		if (parsing_return == 0)
			shexit(&shell, 1);
		if (heredoc_in_main(&shell, &line) == -1)
			continue ;
		if (execute_all_cmds(&shell) != 0)
			shexit(&shell, 1);
		last_part_of_code(&shell, &line);
	}
	shexit(&shell, shell.last_exit_code);
	return (EXIT_SUCCESS);
}
