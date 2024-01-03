/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shexit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:44:28 by fseles            #+#    #+#             */
/*   Updated: 2023/12/05 18:44:29 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

//function that exit shell and clears everything
int	shexit(t_shell *shell, int status)
{
	shell_clear(shell);
	exit(status);
}
