/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 13:06:07 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/24 13:06:09 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * . runs through var
 * . get the length of key in var
 * . malloc space to key_cpy
 * . copy key portion of var to key_cpy
 * . return key_cpy
*/

char	*ft_get_key(char *var)
{
	char	*key_cpy;
	int		key_len;
	int		i;

	key_cpy = NULL;
	key_len = ft_get_key_len(var);
	key_cpy = (char *)malloc(sizeof(char) * (key_len + 1));
	if (!key_cpy)
		return (NULL);
	i = 0;
	while (i < key_len)
	{
		key_cpy[i] = var[i];
		++i;
	}
	key_cpy[i] = '\0';
	return (key_cpy);
}
