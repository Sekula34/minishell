/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 20:12:48 by fseles            #+#    #+#             */
/*   Updated: 2023/12/08 20:12:50 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "data_types.h"

int		append_redirect(t_redirect *append, int *fd);
int		child_executor(t_cmd *cmd, t_shell *shell);
int		child_multi_exec(t_cmd *cmd, t_shell *shell,
			int input_pipe, int output_pipe);
void	clear_mini_env(char ***env_arr);
void	clear_pipe_array(int ***pipe_arr);
void	close_all_pipes(int **pipe_arr);
int		execute_all_cmds(t_shell *shell);
int		execute_builtin(int builtin_num, t_shell *shell, t_cmd *cmd);
int		execute_minishell(t_shell *shell);
int		execute_multiple_cmd(int noc, t_shell *shell);
int		execute_no_cmd(t_shell *shell);
int		execute_original_cmd(t_shell *shell, t_cmd *cmd,
			int original_stdin, int original_stdout);
int		export_exit_status(int exit_number, t_shell *shell);
int		get_argc(char **argv);
void	here_doc_file_delete(t_redirect *heredoc);
int		heredoc_parent_prepare(t_cmd *cmd, t_shell *shell);
int		heredoc_redirect(t_redirect *here_doc, int *fd, t_shell *shell);
void	heredoc_to_zero(t_shell *shell);
int		input_redirect(t_redirect *input, int *fd);
int		is_cmd_builtin(t_cmd *cmd);
int		is_minishell(t_cmd *mini);
int		make_pipes(int ***pipe_arr, int number_of_pipes);
int		one_command_exec(t_cmd *cmd, t_shell *shell);
int		output_redirect(t_redirect *output, int *fd);
int		prepare_fds(t_cmd *cmd, t_shell *shell,
			int input_file, int output_file);
int		redirect_handler(t_redirect *red_list, int *in_fd, int *out_fd);
int		reset_fd(int fd_in, int fd_out, int new_fd_in, int new_fd_out);
int		set_cmd_path(t_cmd *cmd, t_shell *shell);
int		set_mini_env(char ***env_arr, t_vars *head_env);
int		set_number_of_commands(int *noc, t_cmd *cmd);
int		set_original_input_output(int *or_stdin, int *or_stdout);

#endif