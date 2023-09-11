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

char	*ft_copy_key(char *src, char *dest, char stop)
{
	int	key_len;
	int	i;

	if (!src)
		return (NULL);
	key_len = ft_get_key_len(src);
	printf("key_len : %d\n", key_len);
	dest = (char *)malloc(sizeof(char) * (key_len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i] != stop)
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}
