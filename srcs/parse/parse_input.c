/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:48:01 by ftuernal          #+#    #+#             */
/*   Updated: 2023/09/05 15:58:41 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

//objective is to separate meaningfull chunks to pass i tto the exec module
int	parse_input(t_data *in, char **env)
{
	if (alloc_parse_struct(in) == FAILURE)
		return (FAILURE);
	if (!check_quotes(in->input))
	{
		in->subject_flag = false;
		return (QUOTE);
	}
// separate in a chained list cmd_line then tokens that will be taken by exec part of the program
// then separate each cmd_line into token words
//	if (sep_cmd_line(in) == FAILURE || sep_in_words(in) == FAILURE)
//		return (PARSING_FAILURE);
	if (cust_getenv(in, env) != 0)
		return (ENV);
	return (0);
	//add functions for "" management and redirections
}
