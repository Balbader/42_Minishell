/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:22:06 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/11 14:22:08 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*ft_convert_char_to_node(char *to_add)
{
}

// t_env *ft_exec_export(t_data *data)
t_env *ft_exec_export(t_env *to_add, t_env *env)
{
	t_env	*new_ls
	t_env	*new_head;

	new_lst = env;
	new_head = new_lst;
	while (new_lst)
		new_lst = new_lst->next;
	new_lst->next = to_add;
	return (new_head);
}
