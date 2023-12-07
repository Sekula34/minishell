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
int	shexit(t_vars **head_ex, t_vars **head_env, int status)
{
	clear_list_env(head_env);
	clear_list_env(head_ex);
	exit(status);
}
