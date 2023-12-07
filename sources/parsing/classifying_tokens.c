/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classifying_tokens.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:59:09 by wvan-der          #+#    #+#             */
/*   Updated: 2023/12/07 16:50:57 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"


int	is_input(t_tokens *tok)
{

	//protect
	//fill
	//add t0 back
}
int	is_output(t_tokens *tok)
{

}
int	is_heredoc(t_tokens *tok)
{

}
int	is_append(t_tokens *tok)
{

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
		else
		{
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
		else
		{
		 //is error
		}
	}
}

int	classify_filename(t_tokens *tok, int *j)
{
	char *filename;
	
	(*j)++;
	filename = ft_strdup(tok->fin[*j]);
	if (!filename)
		return (0);
	//putname
}

int	fill_redirect_node(t_tokens *tok, int *j)
{
	//makenode
	classify_redirect(tok, *j);
	classify_filename(tok, j);
}

int	put_cmd(t_tokens *tok, int *j)
{
	char *cmd;

	cmd = ft_strdup(tok->fin[*j]);
	if (!cmd)
		return (0);
	//putcmd
}

int classifiying_tokens(t_tokens *tok)
{
	int j;
	int	i;
	char flag;
	int	cmd_flag;
	
	j = 0;
	flag = 'n';
	cmd_flag = 0;
	while (tok->fin[j])
	{
		if (tok->fin[j][0] == '"' && tok->fin[j][1] == 0)
		{
			j++;
			continue;
		}
		else if (is_redirect(tok->fin[j][0]))
		{
			//fill_redirect_node(tok, &j);
			flag = 'f';
			puts("r");
			puts("f");
		}
		else if (flag != 'c' && cmd_flag != 1 && (j == 0 || is_redirect(tok->fin[j - 1][0]) == 0))
		{
			//put_cmd(tok, &j);
			flag = 'c';
			puts("c");
			cmd_flag = 1;
		}
		else if ((flag == 'c' || flag == 'a'))// && is_redirect(tok->fin[j][0]) == 0)
		{
			//arg
			flag = 'a';
			puts("a");
		}
		j++;
	}
}