/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classifying_tokens.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:59:09 by wvan-der          #+#    #+#             */
/*   Updated: 2023/12/06 15:31:59 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"


int	is_input(t_tokens *tok)
{
	//create node
	//protect
	//fill
	//add t0 back
}
int	is_output(t_tokens *tok)
{
	//create node
}
int	is_heredoc(t_tokens *tok)
{
	//create node
}
int	is_append(t_tokens *tok)
{
	//create node
}


int classify_redirect(t_tokens *tok, int j)
{
	if (tok->fin[j][0] == '<')
	{
		if (tok->fin[j][0] == '<' && tok->fin[j][1] == 0)
		{
			is_input(tok);
		}
		else if (tok->fin[j][1] && tok->fin[j][1] == '<')
		{
			is_heredoc(tok);
		}
		else {
		 //is error
		}
	}
	if (tok->fin[j][0] == '>')
	{
		if (tok->fin[j][0] == '>' && tok->fin[j][1] == 0)
		{
			is_output(tok);
		}
		else if (tok->fin[j][1] && tok->fin[j][1] == '>')
		{
			is_append(tok);
		}
		else {
		 //is error
		}
	}
}


int	first_is_redirect(t_tokens *tok)
{
	classify_redirect(tok, 0);
}

int classifiying_tokens(t_tokens *tok)
{
	int j;
	int	i;

	j = 0;
	while (tok->fin[j])
	{
		if (is_redirect(tok->fin[j][0]))
		{
			first_is_redirect(tok);
		}
		else
		{
			//first is cmd
		}
	}
}