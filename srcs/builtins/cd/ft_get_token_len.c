/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_token_len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:40:17 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/24 15:40:19 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_get_token_len(t_token *token)
{
	int	i;

	if (!token)
		return(0);
	i = 0;
	while (token)
	{
		++i;
		token = token->next;
	}
	return (i);
	
}
