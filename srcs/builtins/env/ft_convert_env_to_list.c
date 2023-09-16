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

t_env	*ft_convert_env_to_list(t_env *env_lst, char **env)
{
	t_env	*head;
	char	*key;
	char	*value;
	int		env_len;
	int		i;

	env_len = ft_get_env_len(env);
	key = NULL;
	value = NULL;
	key = ft_copy_key(env[0], key, '=');
	value = ft_copy_value(env[0], value);
	env_lst = ft_create_new_env_node(key, value);
	head = env_lst;
	i = 1;
	while (i <= env_len)
	{
		key = ft_copy_key(env[i], key, '=');
		value = ft_copy_value(env[i], value);
		env_lst->next = ft_create_new_env_node(key, value);
		env_lst = env_lst->next;
		++i;
	}
	return (head);
}

// t_env	*ft_convert_env_to_list(t_env *env_lst, char **env)
// {
// 	t_env	*head;
// 	char	*key;
// 	char	*value;
// 	int		env_len;
// 	int		i;

// 	env_len = ft_get_env_len(env);
// 	key = NULL;
// 	value = NULL;
// 	key = ft_copy_key(env[0], key, '=');
// 	value = ft_copy_value(env[0], value);
// 	env_lst = ft_create_new_env_node(key, value);
// 	head = env_lst;
// 	i = 1;
// 	while (i <= env_len)
// 	{
// 		key = ft_copy_key(env[i], key, '=');
// 		value = ft_copy_value(env[i], value);
// 		env_lst->next = ft_create_new_env_node(key, value);
// 		env_lst = env_lst->next;
// 		++i;
// 	}
// 	return (head);
// }
