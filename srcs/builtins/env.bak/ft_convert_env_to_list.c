/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_env_to_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 11:43:58 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/09 11:44:00 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * . creates a linked list
 * . Takes **env and copies for each element of **env:
 * 		. env[i] to node->var
 * 		. the key part of env[i] to node->key
 * 		. the value part of env[i] to node->value
*/

t_env	*ft_convert_env_to_list(int env_len, t_env *env_lst, char **env)
{
	t_env	*head;
	char	*var;
	char	*key;
	char	*value;
	int		i;

	var = NULL;
	key = NULL;
	value = NULL;
	var = ft_copy_var(env[0], var);
	key = ft_copy_key(env[0], key, '=');
	value = ft_copy_value(env[0], value);
	env_lst = ft_create_new_env_node(var, key, value);
	head = env_lst;
	i = 1;
	while (i <= env_len)
	{
		var = ft_copy_var(env[i], var);
		key = ft_copy_key(env[i], key, '=');
		value = ft_copy_value(env[i], value);
		env_lst->next = ft_create_new_env_node(var, key, value);
		env_lst = env_lst->next;
		++i;
	}
	return (head);
}