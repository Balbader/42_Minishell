/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:00:43 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/19 16:00:44 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * Need to change that function in order to remove the node targeted by the 
 * variable argument withing the node to delete.
*/

void	ft_remove_node(t_env *node, t_env **env)
{
	t_env	*cur;

	if (!(*env))
		return ;
	cur = *env;
	while (cur != node && cur->next && cur->next != node)
		cur = cur->next;
	if (cur != node && !cur->next)
		return ;
	if (cur == node)
		*env = cur->next;
	else
		cur->next = node->next;
}
