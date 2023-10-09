/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:52:07 by ftuernal          #+#    #+#             */
/*   Updated: 2023/10/09 20:05:27 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	expand(t_token *cmd_line)
{
	t_token	*ptr;
	int		ret;

	ptr = cmd_line;
	ret = 0;
	while (ptr != NULL)
	{
		if ((ptr->type == WORD || ptr->type == FD) && 
			(ft_strchr(ptr->word, '\"') || ft_strchr(ptr->word, '\'')))
			ret = expand_quote_word(ptr, ptr->word);
		else if ((ptr->type == WORD || ptr->type == FD))
			ret = expand_noquote_word(ptr, ptr->word);
		if (ret == FAILURE)
			return (FAILURE);
		ptr = ptr->next;
	}
	exec(cmd_line);
	return (SUCCESS);
}
