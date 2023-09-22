/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compare_keys.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:09:10 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/19 13:09:11 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_compare_keys(char *key, char *key_cpy)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (key[i] == key_cpy[j] && key[i] && key_cpy[j])
	{
		++i;
		++j;
	}
	return (key[i] - key_cpy[j]);
}
