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

int	parse_input(char *in)
{
	if (*in == '\0')
		return (FAILURE);
	if (!check_quotes(in))
		return (FAILURE);
	if (split_into_words(in) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
