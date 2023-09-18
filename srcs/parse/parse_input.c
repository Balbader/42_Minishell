/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:48:01 by ftuernal          #+#    #+#             */
/*   Updated: 2023/09/18 14:14:56 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//objective is to separate meaningfull chunks to pass i tto the exec module
int	parse_input(t_token *cmd_line, char *input)
{
	if (!check_quotes(input))
		return (FAILURE);
	if (split_into_words(cmd_line, input) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
	//add functions for "" management and redirections
}
