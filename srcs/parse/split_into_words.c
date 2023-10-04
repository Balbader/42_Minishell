/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_into_words.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:51:09 by ftuernal          #+#    #+#             */
/*   Updated: 2023/10/04 20:17:12 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*add_all_words_nodes( char **tab)
{
	t_token	*cmd_line;
	int		i;

	i = 0;
	while (tab[i])
	{
		if (i == 0)
		{
			cmd_line = cmdline_new_node(tab[0]);
			if (!cmd_line)
				return (NULL);
		}
		else
			if (append_cmd_node(cmd_line, tab[i]) == FAILURE)
				return (NULL);
		if (!cmd_line)
			return (NULL);
		i++;
	}
	return (cmd_line);
}

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
	int	flag;

	flag = false;
	if (line[start] == '\"' || line[start] == '\'')
		flag = true;
	while (line[start])
	{
		if (flag == true && quote_on(line, start + 1) == false)
		{
			start += 1;
			break ;
		}
		else if ((flag == false && ft_strchr("\'\"", line[start + 1]) != 0)
			|| (flag == false && ft_isspace(line[start + 1]) == 1))
		{
			start += 1;
			break ;
		}
		else if ((line[start] == ' ' && quote_on(line, start) == false) ||
			(ft_strchr("<|>&", line[start]) != 0 && quote_on(line, start) == false))
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

char **sep_cmdline(char *line)
{
	int		start;
	int		end;
	int		i;
	int		j;
	char	**tab;
	int		count;

	i = 0;
	count = count_token(line);
	tab = ft_calloc(count + 1, sizeof(char *));
	if (!tab)
		return (0);
	j = 0;
	while (j < count)
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
	//in->cmd_line->in = in;
	tab = sep_cmdline(in);
//print_tab(tab);
	if (!tab)
		return (FAILURE);
	token = add_all_words_nodes(tab);
	// ft_free_tabs(tab);
	free(tab);
	if (!token)
		return (FAILURE);
	// ft_free_cmd(cmd);
	tokenizer(token);
	return (SUCCESS);
}
