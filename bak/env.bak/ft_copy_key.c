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

/*
 * Will copy the key section of each env variable to the key variable of
 * each node of the env_lst.
*/

char	*ft_copy_key(char *env_elem, char *key_cpy, char stop)
{
	int	key_len;
	int	i;

	if (!env_elem)
		return (NULL);
	key_len = ft_get_key_len(env_elem);
	key_cpy = (char *)malloc(sizeof(char) * (key_len + 1));
	if (!key_cpy)
		return (NULL);
	i = 0;
	while (env_elem[i] != stop)
	{
		key_cpy[i] = env_elem[i];
		++i;
	}
	key_cpy[i] = '\0';
	return (key_cpy);
}
