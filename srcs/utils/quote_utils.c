/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:58:03 by ftuernal          #+#    #+#             */
/*   Updated: 2023/10/04 13:09:17 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	check_quotes(char *input)
{
	bool	singl_open;
	bool	doubl_open;
	int		i;

	if (!input)
		return (false);
	i = -1;
	singl_open = false;
	doubl_open = false;
	while (input[++i])
	{
		if (input[i] == '\'' && doubl_open == false)
			singl_open = !singl_open;
		else if (input[i] == '\"' && singl_open == false)
			doubl_open = !doubl_open;
	}
	return (!singl_open && !doubl_open);
}

bool	quote_on(const char *input, int index)
{
	int	i;
	bool	simplq_on;
	bool	doublq_on;

	simplq_on = false;
	doublq_on = false;
	i = 0;
	while (i < index)
	{
		if (input[i] == '\'' && input[i + 1] != '\'' && doublq_on == false)
			simplq_on = !simplq_on;
		else if (input[i] == '\"' && simplq_on == false)
			doublq_on = !doublq_on;
		else if (input[i] == '\'' && input[i + 1] == '\'' && simplq_on == false)
			doublq_on = !doublq_on;
		i++;
	}
	return (simplq_on || doublq_on);
}

t_quote	set_quote_type(char quote)
{
	if (quote == '\'')
		return (SQUOTE);
	else if (quote == '\"')
		return (DQUOTE);
	else
		return (NOQUOTE);
}

int		is_quote(char c)
{
	if (c == '\'' || c == '\"')
		return (1);
	return (0);
}

int	is_quote_heredoc(t_token *rdir)
{
	t_token	*ptr;

	ptr = rdir;
	while (ptr != 0)
	{
		if (ptr->type == LIMITOR 
			&& ft_strchr(ptr->word, '\'') == 0 && ft_strchr(ptr->word, '\"') == 0)
			return (false);
		ptr = ptr->next;
	}
	return (true);
}
