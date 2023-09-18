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

t_env	**ft_get_env(char **env)
{
	static t_env	*list;
	int				env_len;

	env_len = ft_get_env_len(env);
	list = NULL;
	if (env)
		list = ft_convert_env_to_list(env_len, list, env);
	else
		return (NULL);
	return (&list);
}
