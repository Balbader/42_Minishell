/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 07:36:56 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/16 07:36:57 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_env	*ft_env_del_one(t_env *env, char *to_del)
{
	t_env	*next;
	t_env	*prev;
	t_env	*head;

	head = env;
	prev = env;
	while (env)
		{
			if (ft_compare_before_equal(env->var, to_del))
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
	return (head);
}

t_env	**ft_get_env(char **env, char *to_add, char *to_del)
{
	static t_env	*list;

	list = NULL;
	if (env)
		list = ft_convert_env_to_list(&list, env);
	else if (to_add)
		ft_add_var_to_env(to_add, &list);
	else if (to_del)
		ft_env_del_one(to_del, &list);
}
