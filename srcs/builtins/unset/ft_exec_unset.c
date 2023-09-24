/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 14:08:36 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/24 14:08:38 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exec_unset(t_token *token)
{
	while (token)
		{
			if (!ft_check_var_to_unset(token->word))
				error_unset(token->word);
			else
				ft_del_from_env(token->word);
			token = token->next;
		}
	return (g_error = 0, true);
}
