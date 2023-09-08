/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_word_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:06:21 by ftuernal          #+#    #+#             */
/*   Updated: 2023/09/06 11:45:14 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	append_word_node(t_cmdlst *cmd_line, const char *line, int start, int len)
{
	t_token	*new_node;

	if (!cmd_line->words->word)
	{
		free(cmd_line->words->word);
		cmd_line->words->word = ft_substr(line, start, len);
		cmd_line->words->next = NULL;
		return (SUCCESS);
	}
	new_node = word_new_node((char *)line, start, len);
	if (!new_node)
		return (FAILURE);
	addback_word_node(&cmd_line->words, new_node);
	return (SUCCESS);
}
