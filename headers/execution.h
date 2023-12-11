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

void clear_pipe_array(int ***pipe_arr);
int input_redirect(t_redirect *input, int *fd);
int is_cmd_builtin(t_cmd *cmd);
int make_pipes(int ***pipe_arr, int number_of_pipes);
int set_number_of_commands(int *noc, t_cmd *cmd);

#endif