/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_var_to_env.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 10:23:14 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/24 10:23:15 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*ft_add_var_to_env(t_env *env, char *to_add)
{
	t_env	*new;

	if (!env)
	{
		env = (t_env *)malloc(sizeof(t_env));
		if (!env)
			return (NULL);
		env->next = NULL;
		env->var = ft_strdup(to_add);
		return (env->var);
	}
	else
	{
		new = (t_env *)malloc(sizeof(t_env));
		if (!new)
			return (NULL);
	}
	ft_get_last_env(env)->next = new;
	new->env = ft_strdup(to_add);
	new->next = NULL;
	return (new);
}
