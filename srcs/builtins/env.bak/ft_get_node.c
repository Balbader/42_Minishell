/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:33:46 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/23 13:33:47 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*ft_get_node(char *var, t_env *env)
{
	if (!var || ft_strchr(var, '='))
		return (NULL);
	while (env && ft_strncmp(env->var, var, ft_strlen(var) + 1) != '='
		&& ft_strncmp(env->var, var, ft_strlen(var) + 1))
		env = env->next;
	return (env);
}
