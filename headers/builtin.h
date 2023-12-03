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

int	echo(char *string, int n_option);
int	env(t_vars *head);
int	export(char *string, t_vars **ex_vars, t_vars **env_vars);
int	pwd(t_vars *head_ex);
int	unset(char *string, t_vars **env_head, t_vars **ex_head);

#endif