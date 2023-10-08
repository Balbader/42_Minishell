/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:59:03 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/04 16:37:25 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * This function is called in main.c in order to free env_lst.
*/

void	ft_del_env(void)
{
	t_env	*env;
	t_env	*tmp;

	tmp = NULL;
	env = *ft_get_all_env();
	while (env->next)
	{
		tmp = env;
		env = env->next;
		free(tmp->var);
		free(tmp->key);
		free(tmp->value);
		free(tmp);
	}
	ft_free_all_env(env);
}
