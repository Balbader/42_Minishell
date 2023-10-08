/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 10:57:13 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/26 10:57:15 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_all_env(t_env *env)
{
	t_env	*tmp;

	while (env)
	{
		tmp = env;
		free(tmp->var);
		free(tmp->key);
		free(tmp->value);
		env = env->next;
		free(tmp);
	}
}
