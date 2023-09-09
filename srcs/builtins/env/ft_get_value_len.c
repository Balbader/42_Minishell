/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_value_len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 13:36:13 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/09 13:36:15 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_get_value_len(char *str)
{
	int	i;
	int len;

	len = 0;
	i = 0;
	while (str[i] != '=')
		++i;
	if (str[i] == '=')
		++i;
	while (str[i])
	{
		++len;
		++i;
	}
	return (len);
}
