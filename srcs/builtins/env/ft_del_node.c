/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 10:36:29 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/10 18:46:52 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*ft_del_node(t_env *env, char *to_del)
{
	t_env	*prev;
	t_env	*start;
	t_env	*next;
	int		pos;

	pos = 0;
	start = env;
	prev = env;
	next = NULL;
	while (env)
	{
		if (ft_compare_keys(env->var, to_del) && pos == 0)
		{
			start = env->next;
			free(env->var);
			free(env->key);
			free(env->value);
			return (start);
		}
		if (ft_compare_keys(env->var, to_del))
		{
			next = env->next;
			free(env->var);
			free(env->key);
			free(env->value);
			prev->next = next;
			free(env);
			break ;
		}
		++pos;
		prev = env;
		env = env->next;
	}
	return (start);
}
