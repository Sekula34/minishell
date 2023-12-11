/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:21:32 by fseles            #+#    #+#             */
/*   Updated: 2023/12/11 16:21:34 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishel.h"


//return 0 on success 
//return 1 if no such file or dir
int input_redirect(t_redirect *input)
{
	char	*file_name;
	int		access_val;
	file_name = input->file_name;
	access_val = access(file_name, F_OK | R_OK);
	if(access_val == -1)
	{
		perror("Input_redirect:");
		return(1);
	}
}