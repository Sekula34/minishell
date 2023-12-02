/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envexport.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fseles <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:05:37 by fseles            #+#    #+#             */
/*   Updated: 2023/11/29 15:05:39 by fseles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVEXPORT_H
# define ENVEXPORT_H
# include "data_types.h"

void	add_element_back(t_vars **head, t_vars *new_element);
t_vars	*create_element(char *key, char *value);
void	clear_list_env(t_vars **head);
int		count_list_elements(t_vars *head);
void	delete_element(t_vars **element_to_delete);
int		env_list_init(t_vars **start, char **envp);
char	*get_key(char *string);
char	*get_value(char *string);
void	list_sort_alpha(t_vars *head);
int		pos_of_equal(char *string);
int		set_key(char **key, char *string);

#endif
