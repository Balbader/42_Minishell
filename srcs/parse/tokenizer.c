/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:12:22 by ftuernal          #+#    #+#             */
/*   Updated: 2023/09/18 14:33:06 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	add_large_token(char *word, int last_token)
{
	if (word[0] == '>' && word[1] == '>')
		return (APPEND);
	else if (word[0] == '<' && word[1] == '<')
		return (HEREDOC);
	else if (last_token == HEREDOC)
		return (LIMITOR);
	else if (last_token == APPEND || last_token == R_OUT || last_token == R_IN)
		return (FD);
	else
		return (WORD);
}

int	add_token(char *word, int last_token)
{
	if (ft_strlen(word) == 1)
	{
		if (*word == '|')
			return (PIPE);
		else if (*word == '<')
			return (R_IN);
		else if (*word == '>')
			return (R_OUT);
	}
	return (add_large_token(word, last_token));
}

void	tokenizer(t_token *cmd_line)
{
	int		last_token;
	t_token	*current;

	last_token = -1;
	current = cmd_line;
	while (current != NULL)
	{
		current->type = add_token(cmd_line->word, last_token);
		last_token = add_token(cmd_line->word, last_token);
		current = current->next;
	}
}
