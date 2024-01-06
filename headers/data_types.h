/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_types.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:22:24 by fseles            #+#    #+#             */
/*   Updated: 2024/01/04 16:42:42 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_TYPES_H
# define DATA_TYPES_H

typedef struct s_vars
{
	char			*key;
	char			*value;
	struct s_vars	*next;
}	t_vars;

typedef struct s_redirect
{
	char			type;
	char 			*file_name;
	int				del_flag;
	//i = < o = > h = << a = >>
	char			*eof;
	int				to_delete;
	struct s_redirect	*next;
}	t_redirect;

typedef struct s_cmd
{
	char			*path;
	char			*cmd;
	char			**args;
	t_redirect		*redirect_lst;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_shell
{
	t_cmd	*cmd_lst;
	t_cmd	*first_cmd_copy;
	int		last_exit_code;
	t_vars	*head_ex;
	t_vars	*head_env;
	char	*minishell_exec;
	char	**mini_env;
	int **pipe_arr;
}	t_shell;

#endif