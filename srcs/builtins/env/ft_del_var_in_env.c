/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_var_in_env.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:27:14 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/23 13:27:16 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void	ft_del_var_in_env(t_env *to_del, t_env **env)
{
	t_env	*cur;

	if (!(*env))
		return ;
	cur = *env;
	while (cur != to_del && cur->next && cur->next != to_del)
		cur = cur->next;
	if (cur != to_del && !cur->next)
		return ;
	if (cur == to_del)
		*env = cur->next;
	else
		cur->next = cur->next;
}
