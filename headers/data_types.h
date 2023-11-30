/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_types.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:22:24 by fseles            #+#    #+#             */
/*   Updated: 2023/11/30 11:22:25 by fseles           ###   ########.fr       */
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
	char				*redirect;
	struct s_redirect	*next;
}	t_redirect;

typedef struct s_cmd
{
	char			*path;
	char			**args;
	t_redirect		*redirect_lst;
	struct s_cmd	*next;

}	t_cmd;

typedef struct s_shell
{
	t_cmd	cmd_lst;
	int		last_exit_code;
	t_vars	vars;
}	t_shell;

#endif