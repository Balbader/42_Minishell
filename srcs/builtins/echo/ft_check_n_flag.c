/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_n_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 14:13:39 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/24 14:13:40 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * checks if the -n flag has been added to the echo cmd
*/

int	ft_check_n_flag(char *input)
{
	if (!*input)
		return (true);
	while (*input)
	{
		if (*input != '-' && *input != 'n' && *input != ' ')
			return (false);
		++input;
	}
	return (true);
}
