/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:31:33 by fseles            #+#    #+#             */
/*   Updated: 2023/11/28 13:31:35 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

int cd_exec(t_shell *shell, t_cmd *cd_cmd);
int		cd(char *directory, t_vars **ex_head, t_vars **env_head);
int		create_add_new_elems(char *key, char *value, t_vars **ex, t_vars **env);
int		echo(char *string, int n_option);
int		env(t_vars *head);
int		export(char *string, t_vars **ex_vars, t_vars **env_vars);
char	*get_home_path(t_vars *ex_head);
int		key_checker(char *string);
int		pwd(t_vars **head_ex, t_vars **head_env);
int		shexit(t_vars **head_ex, t_vars **head_env, int status);
int		unset(char *string, t_vars **env_head, t_vars **ex_head);

#endif