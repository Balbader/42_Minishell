/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:22:06 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/11 14:22:08 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*ft_convert_char_to_node(char *new_last)
{
	char	*key;
	char	*value;
	t_env	*new_node;

	key = NULL;
	value = NULL;
	key = ft_copy_key(new_last, key, '=');
	value = ft_copy_value(new_last, value);

	new_node = ft_create_new_env_node(key, value);
	return (new_node);
}

t_env	*ft_export_var_to_env(char *new_last, t_env *env)
{
	t_env	*new_lst;
	t_env	*new_head;
	t_env	*to_add;

	new_lst = env;
	new_head = new_lst;
	while (new_lst->next != NULL)
		new_lst = new_lst->next;
	to_add = (t_env *)malloc(sizeof(t_env));
	if (!to_add)
		return  (NULL);
	to_add = ft_convert_char_to_node(new_last);
	new_lst->next = to_add;
	return (new_head);
}

// t_env *ft_exec_export(t_data *data)
t_env *ft_exec_export(char *new_last, t_env *env)
{
}
