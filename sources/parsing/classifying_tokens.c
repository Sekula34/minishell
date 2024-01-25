/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classifying_tokens.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:59:09 by wvan-der          #+#    #+#             */
/*   Updated: 2024/01/22 12:07:39 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

int	put_arg(t_tokens *tok, int *j, t_cmd **cmd_lst)
{
	char	*arg;
	t_cmd	*temp;

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
	if (realloc_array(&temp, arg) == 0)
		return (free(arg), 0);
	return (1);
}

int	make_arg_arr(t_tokens *tok, t_cmd **cmd_lst)
{
	t_cmd	*temp;

	(void)tok;
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
	else if (tok->flag != 'c' && tok->found_cmd_flag != 1 && (*j == 0
			|| is_redirect(tok->fin[*j - 1][0]) == 0))
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

int	check_0_cmd_arg(t_tokens *tok, t_cmd **cmd_lst, t_redirect **redirect_lst)
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
	t_redirect	*redirect_lst;
	t_cmd		*last;
	int			j;

	j = 0;
	redirect_lst = NULL;
	reset_struct(tok);
	while (tok->fin[j])
	{
		if (classify(tok, cmd_lst, &j, &redirect_lst) == 0)
			return (put_error("classifying err"), 0);
		j++;
	}
	if (check_0_cmd_arg(tok, cmd_lst, &redirect_lst) == 0)
		return (put_error("clas err"), clear_redirect_lst(&redirect_lst), 0);
	if (cmd_lst && *cmd_lst)
	{
		last = *cmd_lst;
		while (last->next)
			last = last->next;
		last->redirect_lst = redirect_lst;
	}
	return (1);
}
