/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_and_replace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 10:08:35 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/23 10:08:37 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * 1. con
 * run through env
 * compare to_find && env->key
 * if to_find && env->key are the same
 * 		. replace env->key->value : to_find->value
*/


void	ft_find_and_replace(char *to_find, t_env **env)
{
	t_env	*new_var;
	t_env	*cur;
	// int		new_val_len;

	cur = NULL;
	new_var = NULL;
	new_var = ft_convert_char_to_node(to_find);
	cur = *env;
	while (cur)
	{
		if (ft_strcmp(cur->key, new_var->key) == 0)
		{
			printf("new_var->key : %s\n", new_var->key);
			printf("new_var->value : %s\n", new_var->value);
			printf("cur->key : %s\n", cur->key);
			printf("cur->value : %s\n", cur->value);
		}
		cur = cur->next;
	}
}