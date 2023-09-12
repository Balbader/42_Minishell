/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:58:11 by ftuernal          #+#    #+#             */
/*   Updated: 2023/09/12 16:56:07 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"

int	expand(t_data *in)
{
	t_token	*ptr;
	int		ret;

	ptr = in->cmd_line;
	while (ptr != NULL)
	{
		if ((ptr->token == WORD || ptr->token == FD) && 
			(ft_strchr(ptr->word, '\"') || ft_strchr(ptr->word, '\'')))
			ret = expand_quote_word(ptr, ptr->word);
		else if ((ptr->token == WORD || ptr->token == FD))
			ret = expand_simple_word(ptr, ptr->word);
		if (ret == FAILURE)
			return (FAILURE);
		ptr = ptr->next;
	}
	if (check_arglist(in->cmd_line) == FAILURE)
		return (FAILURE);
	else
		return (SUCCESS);
}
