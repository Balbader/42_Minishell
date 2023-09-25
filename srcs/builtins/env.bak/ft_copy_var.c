/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 09:55:32 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/16 09:55:34 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_copy_var(char *original, char *cpy)
{
	int	var_len;
	int	i;

	if (!original)
		return (NULL);
	var_len = ft_get_var_len(original);
	cpy = (char *)malloc(sizeof(char) * (var_len + 1));
	if (!cpy)
		return (NULL);
	i = 0;
	while (original[i])
	{
		cpy[i] = original[i];
		++i;
	}
	cpy[i] = '\0';
	return (cpy);
}
