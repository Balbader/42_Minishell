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

/*
 * 1. convert var to new_node (var, key, value)
 * 2. compare new_node->key && env->key
 * 3. if cpm(new_node->key && env->key) == true
 * 		. replace env->key->value with new_node->value
 * 4. if cpm(new_node->key && env->key) == false
 * 		. add new_node to env
*/

t_env *ft_exec_export(char *var, t_env *env)
{
	(void)var;
	(void)env;
	return (NULL); 
}
