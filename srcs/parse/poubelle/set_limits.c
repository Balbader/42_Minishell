/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_limits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:30:48 by ftuernal          #+#    #+#             */
/*   Updated: 2023/09/11 17:38:50 by ftuernal         ###   ########.fr       */
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
