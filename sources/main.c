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

int global_signal;

int main(int argc, char **argv, char **envp)
{
	t_shell shell;
	char *line;
	int	parsing_return;


	ft_printf("global signal is %d\n", global_signal);
	parsing_return = 0;
	if(shell_init(&shell, envp) != 0)
	{
		shexit(&shell, 1);
	}
	// line = "echo $USER";
	// heredoc_expand(&shell, &line);
	// return (0);

	int i = 0;
	while(1)
	{
		ft_printf("global signal is %d\n", global_signal);
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

		//line = readline("minishell: ");
		// if (!line)
		//  	shexit(&shell, 0);

		// line = "echo \"$USER\"";
		//line = "echo $$$$ hello'test' $USER \"$USER\" | wc -l";

		if (line == NULL)
		{
			free(line);
			break;
		}
		add_history(line);
		parsing_return = parsing(&shell, line);
		if (parsing_return == 2)
		{
			export_exit_status(2, &shell);
			free(line);
			continue;
		}
		shell.first_cmd_copy = shell.cmd_lst;
		if (parsing_return == 0)
			shexit(&shell, 1);
 		if(heredoc_parent_prepare(shell.cmd_lst, &shell) != 0)
		 	shexit(&shell, 1);
		if(execute_all_cmds(&shell) != 0)
			shexit(&shell, 1);
		clear_all_commands(&shell.first_cmd_copy);
		shell.first_cmd_copy = NULL;
		i++;
		free(line);
		line = NULL;
		rl_on_new_line();
	}
	shexit(&shell, shell.last_exit_code);
	return(EXIT_SUCCESS);
}
