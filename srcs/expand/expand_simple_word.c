/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_simple_word.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:49:17 by ftuernal          #+#    #+#             */
/*   Updated: 2023/09/12 18:16:19 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"

int	expand_simple_word(t_token *cmd_line, char *parse_word)
{
	char	*expand_word;

	if (ft_strchr(parse_word, "$") != 0)
	{
		while (parse_word[i])
		{
			while (parse_word[i] != '$')
				i++;
			tmp = ft_substr();
			if (!tmp)
				return (FAILURE);
		var = get_var(cmd_line->var_lst);
		}
	}
	return (SUCCESS);
}
