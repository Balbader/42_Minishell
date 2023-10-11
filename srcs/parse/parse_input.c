/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:48:01 by ftuernal          #+#    #+#             */
/*   Updated: 2023/10/09 20:42:23 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_totally_space(char *in)
{
	int	i;

	i = 0;
	while (ft_isspace(in[i]) != 0)
		i++;
	if (i < (int)ft_strlen(in))
		return (false);
	return (true);
}

int	parse_input(char *in)
{
	if (*in == '\0')
		return (FAILURE);
	else if (is_totally_space(in) == true)
		return (FAILURE);
	if (!check_quotes(in))
		return (FAILURE);
	if (split_into_words(in) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
