/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_quote_word.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:46:28 by ftuernal          #+#    #+#             */
/*   Updated: 2023/09/14 15:01:38 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"

void	substitute_word(t_token *cmd_line, char *substitute)
{
	int	size;

	size = (int)ft_strlen(substitute) + 1;
	cmd_line->word = ft_strlcpy(cmd_line->word, substitute, len);
}

int	expand_quote_word(t_token *cmd_line, char *word)
{
	char	*tmp;
	char	*dollarfree_str;
	t_quote	quote_type;

	quote_type = set_quote_type(word[0]);
	tmp = quote_remove(word);
	if (quote_type == DQUOTE && ft_strchr(tmp, "$") != 0)
	{
		dollarfree_str = expand_var(tmp);
		if (!dollarfree_str)
			return (free(tmp), FAILURE);
		substitute_word(cmd_line, dollarfree_str);
		free(dollarfree_str);
	}
	else
		substitute_word(cmd_line, tmp);
	return (free(tmp), SUCCESS);
}

int	expand_noquote_word(t_token *cmd_line, char *word)
{
	char	*tmp;

	if (ft_strchr(word, "$") != 0)
	{
		tmp = expand_var(word);
		if (!tmp)
			return (FAILURE);
	}
	else
		return (SUCCESS);
	substitute_word(cmd_line, tmp);
	free(tmp);
	return (SUCCESS);
}
