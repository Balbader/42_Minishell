/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 13:39:48 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/11 09:48:12 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exec_export(t_token *token)
{
	char	*nk;
	char	*cpy;

	while (token)
	{
		if (!token)
			return (true);
		if (!ft_strchr_bool(token->word, '=') && token->next == NULL)
			return (true);
		else if (!ft_strchr_bool(token->word, '='))
			token = token->next;
		cpy = token->word;
		if (ft_isdigit(*cpy) == 1 || token->word[0] == '=')
			return (g_error = 1, ft_print_export_error(cpy), true);
		if (!ft_check_cpy(&cpy))
			return (true);
		cpy = ((nk = ft_copy_key_and_equal(token->word, nk), ft_strdup(cpy)));
		free(token->word);
		ft_does_value_exist(nk);
		token->word = ft_strjoin(nk, cpy);
		free(nk);
		free(cpy);
		token = ((ft_add_to_env(token->word), token->next));
	}
	return (true);
}
