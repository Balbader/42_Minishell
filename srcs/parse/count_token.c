/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:11:00 by ftuernal          #+#    #+#             */
/*   Updated: 2023/10/10 18:54:26 by ftuernal         ###   ########.fr       */
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
	start = 0;
	count = 1;
	end = 0;
	while (i < (int)ft_strlen(line) && line[i])
	{
		start = set_start_word(line, i);
		end = set_end_word(line, start);
		i = end;
		count++;
	}
	return (count);
}
