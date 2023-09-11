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

t_env	*ft_create_new_env_node(int id)
{
	t_env	*new_node;

	new_node = (t_env *)malloc(sizeof(t_env));
	if (!new_node)
		return (NULL);
	new_node->id = id;
	new_node->key = NULL;
	new_node->value = NULL;
	new_node->next = NULL;
	return (new_node);
}

t_env	*ft_create_env_list(int env_len, t_env *env_lst)
{
	t_env	*head;
	int		i;

	head = env_lst;
	i = 0;
	while (i < env_len)
	{
		env_lst->next = ft_create_new_env_node(i);
		++i;
	}
	return (head);
}

t_env	*ft_assign_env_list(char **env, t_env *env_lst)
{
	(void)env;
	(void)env_lst;
	return (NULL);
}

t_env	*ft_convert_env_to_list(char **env)
{
	(void)env;
	return (NULL);
}
