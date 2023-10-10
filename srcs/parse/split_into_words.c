/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_into_words.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:51:09 by ftuernal          #+#    #+#             */
/*   Updated: 2023/10/09 21:24:05 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	set_start_word(char *line, int i)
{
	int	start;

	start = i;
	while (ft_isspace(line[i]) == 1)
	{
		i++;
		start++;
	}
	return (start);
}

int	set_end_word_2(char *line, int start)
{
	while (line[start])
	{
		if (quote_on(line, start) == false
			&& (line[start] == ' ' || ft_strchr("<|>&", line[start] != 0)))
			break ;
		start++;
	}
	return (start);
}

int	set_end_word(char *line, int start)
{
	if (line[start] == 0)
		return (0);
	if (ft_strchr("<|>&", line[start]) != 0)
	{
		start++;
		if ((line[start - 1] != '|' && line[start - 1] != '&')
			&& line[start] == '<')
			start ++;
		else if ((line[start - 1] != '|' && line[start - 1] != '&')
			&& line[start] == '>')
			start++;
		return (start);
	}
	start = set_end_word_2(line, start);
	return (start);
}

char	**sep_cmdline(char *line)
{
	int		start;
	int		end;
	int		i;
	int		j;
	char	**tab;

	i = 0;
	tab = ft_calloc(count_token(line) + 1, sizeof(char *));
	if (!tab)
		return (0);
	j = 0;
	while (j < count_token(line) && line[i])
	{
		start = set_start_word(line, i);
		end = set_end_word(line, start);
		tab[j] = ft_substr(line, start, end - start);
		if (!tab[j])
			return (NULL);
		while (i < end && line[i])
			i++;
		j++;
	}
	tab[j] = NULL;
	return (tab);
}

int	split_into_words(char *in)
{
	char	**tab;
	t_token	*token;

	tab = sep_cmdline(in);
	if (!tab)
		return (FAILURE);
	token = add_all_words_nodes(tab);
	free(tab);
	if (!token)
		return (FAILURE);
	if (tokenizer(token) == FAILURE)
		return (ft_delete_all(&token), FAILURE);
	return (SUCCESS);
}
