/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sep_cmdline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:18:45 by ftuernal          #+#    #+#             */
/*   Updated: 2023/09/12 10:50:39 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

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
	while (line[start])
	{
		if ((line[start] == ' ' && quote_on(line, start) == false)
			|| (ft_strchr("<|>&", line[start]) != 0 
			&& quote_on(line, start) == false))
			break ;
		start++;
	}
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
