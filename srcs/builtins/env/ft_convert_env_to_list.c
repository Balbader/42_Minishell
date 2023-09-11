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
 * Will create a linked list with every env variable
 * Each variable will be assigned to a node.
*/

t_env	*ft_convert_env_to_list(int env_len, t_env *env_lst, char **env)
{
	t_env	*head;
	char	*key;
	char	*value;
	int		i;

	(void)env_len;
	key = NULL;
	value = NULL;
	key = ft_copy_key(env[0], key, '=');
	value = ft_copy_value(env[0], value);
	env_lst = ft_create_new_env_node(0, key, value);
	head = env_lst;
	i = 1;
	while (i <= env_len)
	{
		key = ft_copy_key(env[i], key, '=');
		value = ft_copy_value(env[i], value);
		env_lst->next = ft_create_new_env_node(i, key, value);
		env_lst = env_lst->next;
		++i;
	}
	return (head);
}
