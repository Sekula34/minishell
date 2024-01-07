/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classifying_tokens.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:59:09 by wvan-der          #+#    #+#             */
/*   Updated: 2024/01/07 15:19:47 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

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
	}
	return (1);
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

int	fill_redirect_node(t_tokens *tok, int *j, t_redirect **redirect_lst)
{
	t_redirect *new_node;
	char type;
	char *file_name;


	type = classify_redirect(tok, *j);
	file_name = classify_filename(tok, j);

/* 	printf("type:%c\n", type);
	printf("filename:%s\n", file_name); */

	new_node = make_redirect_node(type, file_name);
	if (!new_node)
	{
		//Free
		return (0);
	}
	//printf("%c, %s\n", new_node->type, new_node->file_name);
	add_redirect_node(redirect_lst, new_node);
	//redirect_lst = redirect_lst->next;
	//printf("%c, %s\n", (*redirect_lst)->type, (*redirect_lst)->file_name);
	return (1);
}

int	put_cmd(t_tokens *tok, int *j, t_cmd **cmd_lst, t_redirect *redirect_lst)
{
	t_cmd *new_node;
	char *cmd;

	cmd = ft_strdup(tok->fin[*j]);
	//cmd = NULL;
	if (!cmd)
		return (0);
	new_node = make_cmd_node(cmd, redirect_lst, *cmd_lst);
	//new_node = NULL;
	if (!new_node)
		return (free(cmd), 0);
	//printf("cmd:%s\n", new_node->cmd);
	add_cmd_node(cmd_lst, new_node);
	//cmd_lst = cmd_lst->next;
	//printf("cmd:%s\n", (*cmd_lst)->cmd);
	return (1);
}

int	get_array_size(t_cmd *cmd_lst)
{
	int	size;

	size = 0;
	while (cmd_lst->args && cmd_lst->args[size])
	{
		size++;
	}
	return (size);
}

int realloc_array(t_tokens *tok, t_cmd **cmd_lst, char *arg)
{
    int size;
    char **temp;
	int	i;

	i = 0;
    size = get_array_size(*cmd_lst);
    temp = (char **)malloc(sizeof(char *) * (size + 2));
    if (!temp)
        return (0);
    while (i < size)
	{
        temp[i] = (*cmd_lst)->args[i];
        i++;
    }
    temp[size] = arg;
    temp[size + 1] = NULL;
    free((*cmd_lst)->args);
    (*cmd_lst)->args = temp;
    return (1);
}

int put_arg(t_tokens *tok, int *j, t_cmd **cmd_lst)
{
	char *arg;
	t_cmd *temp;

	temp = *cmd_lst;

	while (temp && temp->next)
		temp = temp->next;

	arg = ft_strdup(tok->fin[*j]);
	//arg = NULL;
	if (!arg)
		return (0);
	if (!temp->args)
	{
		temp->args = malloc(sizeof(char *) * 2);
		if (!temp->args)
			return (free(arg), 0);
		temp->args[0] = "minishell";
		temp->args[1] = NULL;
	}
	if (realloc_array(tok, &temp, arg) == 0)
		return (free(arg), 0);
	return (1);
}

int	make_arg_arr(t_tokens *tok, t_cmd **cmd_lst)
{
	t_cmd *temp;

	temp = *cmd_lst;
	temp->args = malloc(sizeof(char *) * 2);
	if (!temp->args)
		return (0);
	temp->args[0] = "filip2";
	temp->args[1] = NULL;
	return (1);
}

int	classifiying_tokens(t_tokens *tok, t_cmd **cmd_lst)
{
	t_redirect *redirect_lst;
	int j;
	int	i;
	char flag;
	int	cmd_flag;
	int	found_arg_flag = 0;
	
	j = 0;
	flag = 'n';
	cmd_flag = 0;
	redirect_lst = NULL;
	while (tok->fin[j])
	{
		if (tok->fin[j][0] == '"' && tok->fin[j][1] == 0)
		{
			j++;
			continue;
		}
		else if (is_redirect(tok->fin[j][0]))
		{
			fill_redirect_node(tok, &j, &redirect_lst);
			//printf("--%c, %s\n", redirect_lst->type, redirect_lst->file_name);
			flag = 'f';
/* 			puts("r");
			puts("f"); */
		}
		else if (flag != 'c' && cmd_flag != 1 && (j == 0 || is_redirect(tok->fin[j - 1][0]) == 0))
		{
			if (put_cmd(tok, &j, cmd_lst, redirect_lst) == 0)
				return (0);
			flag = 'c';
/* 			puts("c"); */
			cmd_flag = 1;
		}
		else if ((flag == 'c' || flag == 'a'))// && is_redirect(tok->fin[j][0]) == 0)
		{
			if (put_arg(tok, &j, cmd_lst) == 0)
				return (0);
			flag = 'a';
			found_arg_flag = 1;
/* 			puts("a"); */
		}
		j++;
	}

	if (found_arg_flag == 0)
	{
		if (make_arg_arr(tok, cmd_lst) == 0)
			return (0);
	}
	(*cmd_lst)->redirect_lst = redirect_lst;

	/* return (cmd_lst); */
	return (1);
}
