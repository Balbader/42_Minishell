/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sep_cmdline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:18:45 by ftuernal          #+#    #+#             */
/*   Updated: 2023/09/11 16:46:39 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

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
/*
int	sep_cmdline(char ***tab, char *line, int (*set_start)(char *))
{
	int	lim[2];

	lim[START] = set_start(line);
	lim[END] = set_end_word(line, lim[START]);
	if (lim[END] > 0)
	{
		if (sep_cmdline(tab, line + lim[END], set_start(line)) == FAILURE)
			return (FAILURE);
		(*tab)[idx] = ft_substr(line, lim[START], lim[END] - lim[START]);
		if (!(*tab)[idx])
			return (FAILURE);
	}
	else if (lim[END] == 0)
	{
		(*tab) = (char **)malloc(sizeof(char *) * (idx + 1));
		if (!(*tab))
			return (FAILURE);
		(*tab)[idx] = NULL;
	}
	return (SUCCESS);
}
*/
