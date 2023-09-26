/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_var_to_env.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:13:45 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/23 13:13:47 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_add_var_to_env(char *var, t_env **env)
{
	t_env	*cur;
	t_env	*new;
	int		var_len;

	if (!env || !var)
		return ;
	var_len = ft_get_var_len(var);
	new = NULL;
	new = ft_convert_char_to_node(var);
	cur = *env;
	while (cur->next)
		cur = cur->next;
	cur->next = new;
}
