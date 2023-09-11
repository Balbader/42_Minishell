/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 08:50:42 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/11 08:50:44 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_copy_key(char *key, char *key_cpy, char stop)
{
	int	key_len;
	int	i;

	if (!key)
		return (NULL);
	key_len = ft_get_key_len(key);
	key_cpy = (char *)malloc(sizeof(char) * (key_len + 1));
	if (!key_cpy)
		return (NULL);
	i = 0;
	while (key[i] != stop)
	{
		key_cpy[i] = key[i];
		++i;
	}
	key_cpy[i] = '\0';
	return (key_cpy);
}
