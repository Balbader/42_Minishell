/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:52:07 by ftuernal          #+#    #+#             */
/*   Updated: 2023/09/18 14:45:51 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	expand(t_token *cmd_line)
{
	t_token	*ptr;
	int		ret;

	ptr = cmd_line;
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
//	if (check_arglist(cmd_line) == FAILURE)
//		return (FAILURE);
//	else
	return (SUCCESS);
}
