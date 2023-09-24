/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 12:06:32 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/24 12:06:34 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * Searches the value of the givev var in env
 * if found, returns a pointer to the begining of tha value which is the string
 * starting after the '=' character.
 * if not found, returns NULL;
*/
char	*ft_find_value(char *var)
{
	t_env	*env;
	char	*tmp;

	if (!var)
		return (NULL);
	env = *ft_get_all_env();
	while (env)
		{
			if (ft_compare_keys(env->var, var))
			{
				tmp = env->var;
				while (*tmp != '=')
					++tmp;
				++tmp;
				return (tmp);
			}
			env = env->next;
		}
	return (NULL);
}
