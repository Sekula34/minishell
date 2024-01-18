/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classifying_tokens.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:59:09 by wvan-der          #+#    #+#             */
/*   Updated: 2024/01/18 18:39:53 by wvan-der         ###   ########.fr       */
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

int rm_quotes_from_filename(char **filename)
{
	char *temp;
	int len;
	int i;
	int j;

	i = 1;
	j = 0;
	if (is_quote((*filename)[0]) == 0)
		return (1);
	len = ft_strlen(*filename);
	temp = (char *)malloc(len - 1);
	if (!temp)
		return (free(*filename), 0);
	while (i < len - 1)
	{
		temp[j] = (*filename)[i];
		i++;
		j++;
	}
	temp[j] = 0;
	free(*filename);
	*filename = temp;
	return (1);
}

char *make_filename(t_tokens *tok, int *j)
{
	char *filename;
	
	(*j)++;
	filename = ft_strdup(tok->fin[*j]);
	if (!filename)
		return (NULL);
	convert_fake_redirect_back(&filename);
	if (rm_quotes_from_filename(&filename) == 0)
		return (NULL);
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
	file_name = make_filename(tok, j);
	if (!file_name)
		return (0);
	new_node = make_redirect_node(type, file_name);
	if (!new_node)
		return (free(file_name), 0);
	add_redirect_node(redirect_lst, new_node);
	return (1);
}

int	put_cmd(t_tokens *tok, int *j, t_cmd **cmd_lst, t_redirect *redirect_lst)
{
	t_cmd *new_node;
	char *cmd;

	cmd = ft_strdup(tok->fin[*j]);
	if (!cmd)
		return (0);
	convert_fake_redirect_back(&cmd);
	new_node = make_cmd_node(cmd, redirect_lst, *cmd_lst);
	if (!new_node)
		return (free(cmd), 0);
	add_cmd_node(cmd_lst, new_node);
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
	if (!arg)
		return (0);
	convert_fake_redirect_back(&arg);
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
	if (!temp)
		return (1);
	while (temp->next)
		temp = temp->next;
	temp->args = malloc(sizeof(char *) * 2);
	if (!temp->args)
		return (0);
	temp->args[0] = "cmd name";
	temp->args[1] = NULL;
	return (1);
}

int	classify(t_tokens *tok, t_cmd **cmd_lst, int *j, t_redirect **redirect_lst)
{
	if (is_redirect(tok->fin[*j][0]))
	{
		if (fill_redirect_node(tok, j, redirect_lst) == 0)
			return (0);
		tok->flag = 'f';
	}
	else if (tok->flag != 'c' && tok->found_cmd_flag != 1 && (*j == 0 || is_redirect(tok->fin[*j - 1][0]) == 0))
	{
		if (put_cmd(tok, j, cmd_lst, *redirect_lst) == 0)
			return (0);
		tok->flag = 'c';
		tok->found_cmd_flag = 1;
	}
	else if ((tok->flag == 'c' || tok->flag == 'a' || tok->flag == 'f'))
	{
		if (put_arg(tok, j, cmd_lst) == 0)
			return (0);
		tok->flag = 'a';
		tok->found_arg_flag = 1;
	}
	return (1);
}

int	check_0_cmd_or_arg(t_tokens *tok, t_cmd **cmd_lst, t_redirect **redirect_lst)
{
	t_cmd	*new;

	if (tok->found_cmd_flag == 0)
	{
		new = make_cmd_node(NULL, *redirect_lst, *cmd_lst);
		if (!new)
			return (0);
		add_cmd_node(cmd_lst, new);
	}
	if (tok->found_arg_flag == 0)
	{
		if (make_arg_arr(tok, cmd_lst) == 0)
			return (0);
	}

	return (1);
}

int	classifiying_tokens(t_tokens *tok, t_cmd **cmd_lst)
{
	t_redirect *redirect_lst;
	t_cmd *last;
	int j;
	
	j = 0;
	redirect_lst = NULL;
	reset_struct(tok);
	while (tok->fin[j])
	{
		if (classify(tok, cmd_lst, &j, &redirect_lst) == 0)
			return (puts("1"), 0);
		j++;
	}
	if (check_0_cmd_or_arg(tok, cmd_lst, &redirect_lst) == 0)
		return (0);
	if (cmd_lst && *cmd_lst)
	{
		last = *cmd_lst;
		while (last->next)
			last = last->next;
		last->redirect_lst = redirect_lst;
	}
	return (1);
}
