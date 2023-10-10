/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_env_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 10:29:52 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/24 10:29:54 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*ft_create_env_list(char **env)
{
	t_env	*lst;
	t_env	*tmp;

	lst = NULL;
	tmp = NULL;
	while (*env)
	{
		if (!ft_add_var_to_env(&lst, *env))
		{
			while (lst)
			{
				tmp = lst;
				lst = lst->next;
				free(tmp->var);
				free(tmp);
			}
			return (NULL);
		}
		env++;
	}
	return (lst);
}
