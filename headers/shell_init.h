/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:20:49 by fseles            #+#    #+#             */
/*   Updated: 2023/12/13 15:20:51 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_INIT_H
# define SHELL_INIT_H
# include "data_types.h"

void clear_all_commands(t_cmd **cmd_list);
void clear_redirects(t_redirect **list);
int shell_init(t_shell *shell, char **envp);
void shell_clear(t_shell *shell);

#endif