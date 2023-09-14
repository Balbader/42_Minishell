/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_many_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:01:19 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/14 12:01:21 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * starting form token[1]:
 * . extract the str from the token
 * . split the str into key & value
 * . create new node 
 * . add key & value to new node
 * . add  new node to end of env
 * . return env after adding all tokens
*/

t_env	*ft_export_many_args(t_token *token, t_env *env)
{
	t_env	*new_env;
	t_env	*new_head;
	int	token_count;
	int	i;

	new_env = env;
	new_head = NULL;
	new_head = ft_add_var_to_env(token->word, new_env);
	return (new_head);
}
