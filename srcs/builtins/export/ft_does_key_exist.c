/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_does_key_exist.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:02:19 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/19 10:02:21 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * make a copy of token key to be added to env
 * run through tmp_env and check if the token key alrady exist in env
 * if yes return (1);
 * if no return (0);
*/

int	ft_does_key_exist(char *token_word, t_env *env)
{
	t_env	*tmp_env;
	char	*token_key_cpy;

	tmp_env = NULL;
	token_key_cpy = NULL;
	tmp_env = env;
	token_key_cpy = ft_copy_key(token_word, token_key_cpy, '=');
	while (tmp_env->next)
		{
			if (ft_compare_keys(token_key_cpy, tmp_env->key) == 1)
				tmp_env = tmp_env->next;
			else if (ft_compare_keys(token_key_cpy, tmp_env->key) == 0)
				return (1);
			tmp_env = tmp_env->next;
		}
	return (0);
}
