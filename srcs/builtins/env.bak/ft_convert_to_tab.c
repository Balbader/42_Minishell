/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_to_tab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:39:45 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/23 13:39:47 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_convert_to_tab(t_env *env)
{
	t_env	*cur;
	char	**tab;
	int		len;

	len = 0;
	cur = env;
	while (cur && ++len)
		cur = cur->next;
	tab = (char **)malloc(sizeof(char *) * (len + 1));
	if (!tab)
		return (NULL);
	len = 0;
	while (env)
	{
		tab[len++] = env->var;
		env = env->next;
	}
	tab[len] = NULL;
	return (tab);
}
