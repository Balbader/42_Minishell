/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:11:00 by ftuernal          #+#    #+#             */
/*   Updated: 2023/09/19 16:28:59 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_token(char *line)
{
	int	count;
	int	start;
	int	i;
	int	end;

	i = 0;
	count = 0;
	while (i < (int)ft_strlen(line))
	{
		start = set_start_word(line, i);
		end = set_end_word(line, start);
		while (i < end && line[i])
			i++;
//printf("string == %s start == %d end == %d\n", line + start, start, end);
		count++;
	}
	return (count);
}
