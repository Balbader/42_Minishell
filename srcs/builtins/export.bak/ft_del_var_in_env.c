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


t_env	*ft_del_var_in_env(char *to_del, t_env **env)
{
	t_env	*head;
	t_env	*cur;

	cur = (*env);
	head = cur;
	while (cur)
	{
		if (ft_strncmp(cur->var, to_del, '=') == 0)
		{
			printf("********They are the same*******\n");
			cur = cur->next;
			return (head);
		}
		cur = cur->next;
	}
	return (head);
}
