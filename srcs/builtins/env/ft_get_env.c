/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 11:20:15 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/24 11:20:17 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	**ft_get_env(char **env, char *to_add, char *to_del)
{
	static t_env	*list;

	list = NULL;
	if (env)
		list = ft_create_env_list(env);
	else if (to_add)
		list = ft_add_var_to_env(list, to_add);
	else if (to_del)
		list = ft_del_node(list, to_del);
	return (&list);
}
