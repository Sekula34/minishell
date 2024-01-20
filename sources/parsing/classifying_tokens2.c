/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classifying_tokens2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:17:39 by wvan-der          #+#    #+#             */
/*   Updated: 2024/01/19 15:18:18 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishel.h"

char	classify_redirect(t_tokens *tok, int j)
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

int	rm_quotes_from_filename(char **filename)
{
	char	*temp;
	int		len;
	int		i;
	int		j;

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

char	*make_filename(t_tokens *tok, int *j)
{
	char	*filename;

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
	t_redirect	*new_node;
	char		type;
	char		*file_name;

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
	t_cmd	*new_node;
	char	*cmd;

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
