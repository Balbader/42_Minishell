/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_env_to_tab.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 10:52:31 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/24 10:56:24 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_convert_env_to_tab(t_env *env)
{
	char	**start;
	char	**tab;
	int		len;

	len = ft_get_env_len(env);
	tab = (char **)malloc(sizeof(char *) * (len + 1));
	if (!tab)
		return (NULL);
	tab[len] = NULL;
	start = tab;
	while (env)
	{
		*tab = ft_strdup(env->var);
		tab++;
		env = env->next;
	}
	return (start);
}
