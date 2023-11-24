#include "minishel.h"

void	init_struct(t_shell *shell)
{
	shell->last_exit_code = 0;

	shell->cmd_lst.path = NULL;
	shell->cmd_lst.args = NULL;
	shell->cmd_lst.next = NULL;

	shell->cmd_lst.redirect_lst->redirect = NULL;
	shell->cmd_lst.redirect_lst->next = NULL;

	shell->vars.key = NULL;
	shell->vars.value = NULL;
	shell->vars.next = NULL;

}

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;

	init_struct(&shell);
	ft_split(&shell, argv[1]);
}