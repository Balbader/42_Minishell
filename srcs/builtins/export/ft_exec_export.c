/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 13:39:48 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/24 13:39:49 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exec_export(t_token *token)
{
	char	*new_key;
	char	*cpy;
	// t_token	*tmp;

	// tmp = token;
	// while (tmp)
	// {
	// 	printf("token->word : %s\n", tmp->word);
	// 	tmp = tmp->next;
	// }
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
		cpy = ft_strdup(cpy);
		new_key = ft_copy_key_and_equal(token->word, new_key);
		// printf("new_key : %s\n", new_key); 
		free(token->word);
		ft_does_value_exist(new_key);
		token->word = ft_strjoin(new_key, cpy);
		free(new_key);
		free(cpy);
		token = ((ft_add_to_env(token->word), token->next));
	}
	return (true);
}
