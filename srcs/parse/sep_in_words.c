/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sep_in_words.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 09:38:19 by ftuernal          #+#    #+#             */
/*   Updated: 2023/09/06 13:19:27 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
//Not tested
char	*skipspace(char *str)
{
	while (ft_isspace((int)*str) == 1)
		str++;
	return (str);
}

int	split_in_words(t_cmdlst *cmd_line, char *line)
{
	int	i;
	int	j;

	i = 0;
	line = skipspace(line);
	cmd_line->words = ft_calloc(1, sizeof(t_token));
	if (!cmd_line->words)
		return (FAILURE);
	cmd_line->words->word = ft_calloc(1, sizeof(char));
	if (!cmd_line->words->word)
		return (FAILURE);
	while (line[i] && line[i] != '|')
	{
		printf("here i == %d char == %c\n", i, line[i]);
		if (!quote_on(line, i) && ft_isspace((int)line[i]) == 0)
		{
			j = i;
			while (ft_isspace(line[j]) == 0 && !quote_on(line, j) && line[j])
				j++;
			if (append_word_node(cmd_line, line, i, j) == FAILURE)
				return (FAILURE);
			i += j;
		}
		else if (quote_on(line, i))
		{
			j = i;
			while (quote_on(line, j) && line[j])
				j++;
			if (append_word_node(cmd_line, line, i, j) == FAILURE)
				return (FAILURE);
			i += j;
		}
		else
			i++;
	}
	return (SUCCESS);
}

int	sep_in_words(t_data *in)
{
	t_cmdlst	*lst_ptr;

	lst_ptr = in->cmd_line;
	while (in->cmd_line != NULL)
	{
		if (split_in_words(in->cmd_line, in->cmd_line->line) != SUCCESS)
			return (FAILURE);
		in->cmd_line = in->cmd_line->next;
	}
	in->cmd_line = lst_ptr;
	return (SUCCESS);
}
/*
int	process_qoff(t_cmdlst *cmd_line, const char *line, int start) 
{
	int	i;

	i = 0;
	while (line[i] != '\0' && quote_on(line, i) == false)
	{
		if (ft_isspace((int)line[i]) == 1)
		{
			if (append_word_node(cmd_line, line, start, i - start) == FAILURE)
				return (FAILURE);
		}
		i++;
	}
	return (SUCCESS);
}

int	process_qon(t_cmdlst *cmd_line, const char *line, int start)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && quote_on(line, i) == true)
	{
		if (!quote_on(line, i))
		{
			if (append_word_node(cmd_line, line, start, i - start) == FAILURE)
				return (FAILURE);
		}
		i++;
	}
	return (SUCCESS);
}
*/
/*
int	split_in_words(t_cmdlst *cmd_line, char *line)
{
	int	i;
	int	start;

	i = 0;
	while (line[i])
	{
printf("do i do infinite loop %d\n", i);
		if (quote_on(line, i) == false)
		{
			start = i;
			if (process_qoff(cmd_line, line, start) == FAILURE)
				return (FAILURE);
		}
		while (quote_on(line, i) == false && line[i])
			i++;
		if (quote_on(line, i) == true)
		{
			start = i;
			if (process_qon(cmd_line, line, start) == FAILURE)
				return (FAILURE);
		}
		while (quote_on(line, i) == true && line[i])
			i++;
	}
	return (SUCCESS);
}
*/
