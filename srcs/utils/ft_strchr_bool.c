/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_bool.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:17:15 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/03 10:17:17 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	ft_strchr_bool(const char *s, int c)
{
	if ((char)c == '\0')
		return (false);
	while (*s)
	{
		if (*s == (char)c)
			return (true);
		s++;
	}
	return (false);
}
