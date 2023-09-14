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
	int	token_count;

	token_count = ft_get_env_len(token);
}
