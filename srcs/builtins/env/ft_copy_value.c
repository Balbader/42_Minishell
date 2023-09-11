/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 09:09:53 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/11 09:09:55 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_copy_value(char *env_elem, char *value_cpy)
{
	int	value_len;
	int	i;
	int	j;

	if (!env_elem)
		return (NULL);
	value_len = ft_get_value_len(env_elem);
	i = ft_get_key_len(env_elem) + 1;
	value_cpy = (char *)malloc(sizeof(char) * (value_len + 1));
	if (!value_cpy)
		return (NULL);
	j = 0;
	while (env_elem[i])
	{
		value_cpy[j] = env_elem[i];
		++i;
		++j;
	}
	value_cpy[j] = '\0';
	return (value_cpy);
}
