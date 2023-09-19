/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_var_to_env.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 09:53:33 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/18 09:53:35 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * new_last = new variable to add to the end of the env list
 * env = env list that will recieve new_last
 * this function takes the new_last str and converts it to a node
 * then adds the new_last node to the env list
*/

void	ft_export_var_to_env(char *new_last, t_env **env)
{
	t_env	*new_lst;
	t_env	*to_add;

	if (!new_last || !env)
		return ;
	new_lst = *env;
	while (new_lst->next != NULL)
		new_lst = new_lst->next;
	to_add = (t_env *)malloc(sizeof(t_env));
	if (!to_add)
		return ;
	to_add = ft_convert_char_to_node(new_last);
	new_lst->next = to_add;
}
