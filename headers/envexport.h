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
t_vars	*create_element_key_only(char *key);
void	clear_list_env(t_vars **head);
int		count_list_elements(t_vars *head);
void	delete_element(t_vars **element_to_delete);
void	delete_element_with_key(char *key, t_vars **head);
int		env_list_init(t_vars **start, char **envp);
int export_shlvl(t_shell *shell);
t_vars	*get_element(char *key, t_vars *head);
char	*get_plain_key(char *key_with_eq);
void	list_sort_alpha(t_vars *head);
int		pos_of_equal(char *string);
int		set_key(char **key, char *string);
int		set_new_value(t_vars *element, char *new_value);
int		set_value(char **value, char *string);

#endif
