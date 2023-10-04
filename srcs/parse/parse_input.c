/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:48:01 by ftuernal          #+#    #+#             */
/*   Updated: 2023/10/04 17:26:15 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parse_input(char *in)
{
printf("\n-------WE RE IN PARSING-------------i\n\n");
	if (*in == '\0')
		return (FAILURE);
	if (!check_quotes(in))
		return (FAILURE);
	if (split_into_words(in) == FAILURE)
		return (FAILURE);
// print_all_words(in->cmd_line);
printf("\n-------WE LEAVE PARSING-------------i\n\n");
	return (SUCCESS);
}

