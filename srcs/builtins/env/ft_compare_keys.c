/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compare_keys.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 12:00:38 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/24 12:00:48 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_compare_keys(char *key, char *to_find)
{
	if (!to_find)
		return (false);
	while (*to_find && *key && *key != '=' &&
		*to_find != '=' && *key == *to_find)
	{
		++key;
		++to_find;
	}
	if (*key == '=' && (!*to_find || *to_find == '='))
		return (true);
	return (false);
}
