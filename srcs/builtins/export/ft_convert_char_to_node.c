/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_char_to_node.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 10:56:22 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/14 10:56:23 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * new_last = the new variable to add to the env lst
 * new_last is recieved under a str format
 * this function will convert the str to a node that will be manipulated
 * based on the command recieved.
 * var = the full str in its initial state
 * key = the part of the new_last str BEFORE the "="
 * value = the part of the new_last str AFTER the "="
*/

t_env	*ft_convert_char_to_node(char *new_last)
{
	char	*var;
	char	*key;
	char	*value;
	t_env	*new_node;

	var = NULL;
	key = NULL;
	value = NULL;
	var = ft_copy_var(new_last, var);
	key = ft_copy_key(new_last, key, '=');
	value = ft_copy_value(new_last, value);

	new_node = ft_create_new_env_node(var, key, value);
	return (new_node);
}
