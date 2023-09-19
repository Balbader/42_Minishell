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
 * this function will take the token linked list sent by parsing
 * the first token (node) = the command to be executed will be by passed
 * the remaining word (arg) of each token will be added to env
 * only if all the variable are different.
*/

t_env	*ft_export_many_args(t_token *token, t_env *env)
{
	t_env	*new_env;
	t_env	*new_head;

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
