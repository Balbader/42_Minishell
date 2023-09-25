/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 10:36:29 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/24 10:36:30 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*ft_del_node(t_env *env, char *to_del)
{
	t_env	*prev;
	t_env	*start;
	t_env	*next;

	start = env;
	prev = env;
	while (env)
	{
		if (ft_compare_keys(env->var, to_del))
		{
			next = env->next;
			free(env->var);
			free(env);
			prev->next = next;
			break ;
		}
		prev = env;
		env = env->next;
	}
	return (start);
}
