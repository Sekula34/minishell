/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishel.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:43:41 by fseles            #+#    #+#             */
/*   Updated: 2024/01/20 15:04:52 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHEL_H
# define MINISHEL_H
# define NAME "minishel: "
# include <errno.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/ioctl.h>
# include "data_types.h"
# include "shell_init.h"
# include "../libft/libft.h"
# include "parsing.h"
# include "envexport.h"
# include "builtin.h"
# include "execution.h"
# include "signals.h"

extern int	g_signal;

#endif
