/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classifying_tokens.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:59:09 by wvan-der          #+#    #+#             */
/*   Updated: 2023/12/15 18:18:57 by wvan-der         ###   ########.fr       */
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


char classify_redirect(t_tokens *tok, int j)
{
	if (tok->fin[j][0] == '<')
	{
		if (tok->fin[j][0] == '<' && tok->fin[j][1] == 0)
		{
			return ('i');
		}
		else if (tok->fin[j][1] && tok->fin[j][1] == '<')
		{
			return ('h');
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
			return ('o');
		}
		else if (tok->fin[j][1] && tok->fin[j][1] == '>')
		{
			return ('a');
		}
		else
		{
		 //is error
		}
	}
}

char *classify_filename(t_tokens *tok, int *j)
{
	char *filename;
	
	(*j)++;
	filename = ft_strdup(tok->fin[*j]);
	if (!filename)
		return (NULL);
	return (filename);
}

int	fill_redirect_node(t_tokens *tok, int *j, t_redirect *redirect_lst)
{
	t_redirect *new_node;
	char type;
	char *file_name;

	puts("hello");

	type = classify_redirect(tok, *j);
	file_name = classify_filename(tok, j);

	printf("type:%c\n", type);
	printf("filename:%s\n", file_name);

	new_node = make_redirect_node(type, file_name);
	printf("%c, %s\n", new_node->type, new_node->file_name);
	add_redirect_node(&redirect_lst, new_node);
	puts("s");
}

int	put_cmd(t_tokens *tok, int *j, t_cmd *cmd_lst)
{
	t_cmd *new_node;
	char *cmd;

	cmd = ft_strdup(tok->fin[*j]);
	if (!cmd)
		return (0);
	new_node = make_cmd_node(cmd, cmd_lst);
	printf("%s\n", new_node->cmd);
	add_cmd_node(&cmd_lst, new_node);
}

int classifiying_tokens(t_tokens *tok, t_cmd *cmd_lst)
{
	puts("classifying token2");
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
			fill_redirect_node(tok, &j, cmd_lst->redirect_lst);
			flag = 'f';
			puts("r");
			puts("f");
		}
		else if (flag != 'c' && cmd_flag != 1 && (j == 0 || is_redirect(tok->fin[j - 1][0]) == 0))
		{
			put_cmd(tok, &j, cmd_lst);
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
	return (1);
}
