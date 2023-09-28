/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_value_len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:59:07 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/28 18:59:09 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_get_value_len(char *var)
{
	int	i;
	int	val_len;

	val_len = 0;
	i = 0;
	while (var[i] != '=')
		++i;
	++i;
	while (var[i])
	{
		++val_len;
		++i;
	}
	return (val_len);
}
