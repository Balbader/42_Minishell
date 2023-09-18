/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_token_len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:09:46 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/14 13:09:49 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * This function gets the full lenght of the token llist
 * sent to me from parsing
 * in case of an export or unset, this allows me to know :
 * 1. the 1st token = the command to execute -> export or unset
 * 2. the remaining tokens = 
 * 		. the number of variable to export or unset
 * 		. the key/value of each variable to export or unset
*/

int	ft_get_token_len(t_token *token)
{
	int	count;

	count = 0;
	while (token)
	{
		++count;
		token = token->next;
	}
	return (count);
}
