/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_verif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:54:29 by ftuernal          #+#    #+#             */
/*   Updated: 2023/09/21 17:54:31 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parsing_verif(t_token *cmd_line)
{
	t_token	*ptr;
	t_type	last_token;

	last_token = -1;
	ptr = cmd_line;
	while (cmd_line != NULL)
	{
		if (verif_token(cmd_line->type, last_token) == FAILURE)
		{
			strerr_parsing(cmd_line->word);
			return (FAILURE);
		}
		last_token = cmd_line->type;
		ptr = cmd_line;
		cmd_line = cmd_line->next;
	}
	if (!cmd_line)
		if (verif_last_token(last_token, -1) == FAILURE)
			return (strerr_parsing(ptr->word), FAILURE);
	return (SUCCESS);
}
