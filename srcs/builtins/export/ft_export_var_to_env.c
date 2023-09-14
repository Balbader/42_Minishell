/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_var_to_env.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 10:56:28 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/14 10:56:29 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*ft_export_var_to_env(char *new_last, t_env *env)
{
	t_env	*new_lst;
	t_env	*new_head;
	t_env	*to_add;

	new_lst = env;
	new_head = new_lst;
	while (new_lst->next != NULL)
		new_lst = new_lst->next;
	to_add = (t_env *)malloc(sizeof(t_env));
	if (!to_add)
		return  (NULL);
	to_add = ft_convert_char_to_node(new_last);
	new_lst->next = to_add;
	return (new_head);
}
