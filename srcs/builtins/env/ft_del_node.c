/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 10:36:29 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/10 19:29:21 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_free_env_elem(t_env *env)
{
	free(env->var);
	free(env->key);
	free(env->value);
	free(env);
}

static void	ft_run_second_if(t_env *env, t_env *prev, t_env *next)
{
	next = env->next;
	ft_free_env_elem(env);
	prev->next = next;
	// free(env);
}

t_env	*ft_del_node(t_env *env, char *to_del)
{
	t_env	*prev;
	t_env	*start;
	t_env	*next;
	int		pos;

	pos = 0;
	start = ((prev = env, next = NULL, env));
	while (env)
	{
		if (ft_compare_keys(env->var, to_del) && pos == 0)
		{
			start = env->next;
			ft_free_env_elem(env);
			return (start);
		}
		if (ft_compare_keys(env->var, to_del))
		{
			ft_run_second_if(env, prev, next);
			break ;
		}
		++pos;
		prev = env;
		env = env->next;
	}
	return (start);
}
