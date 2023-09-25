/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_new_env_node.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 09:51:09 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/20 10:35:50 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * create a new node that holds :
 * . env variable
 * . Key variable
 * . value variable
 * . ptr to next node
*/

t_env	*ft_create_new_env_node(char *var_cpy, char *key_cpy, char *value_cpy)
{
	t_env	*new_node;

	new_node = (t_env *)malloc(sizeof(t_env));
	if (!new_node)
		return (NULL);
	new_node->var = var_cpy;
	new_node->key = key_cpy;
	new_node->value = value_cpy;
	new_node->next = NULL;
	return (new_node);
}
