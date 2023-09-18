/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_many_args.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 09:53:09 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/18 09:53:10 by baalbade         ###   ########.fr       */
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
	// (void)token;
	// (void)env;
	t_env	*new_env;
	t_env	*new_head;
	int		token_len;

	token_len = ft_get_token_len(token);
	new_head = NULL;
	new_env = env;
	new_head = new_env;
	token = token->next;
	while (token)
	{
		new_env = ft_export_var_to_env(token->word, new_env);
		token = token->next;
	}
	return (new_head);
}
