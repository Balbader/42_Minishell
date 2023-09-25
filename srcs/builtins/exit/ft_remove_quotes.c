/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_quotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:58:19 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/24 15:58:21 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_remove_quotes(char *var)
{
	int		tot_quotes;
	char	*tmp;
	char	*no_quotes;

	tmp = ((tot_quotes = 0, var));
	while (*var)
	{
		if (*var == '\'' || *var == '"')
			++tot_quotes;
		++var;
	}
	if (!*var)
		return (ft_strdup(tmp));
	var = tmp;
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(var) - tot_quotes));
	if (!tmp)
		return (NULL);
	no_quotes = ((tmp[ft_strlen(var) - tot_quotes] = '\0', tmp));
	while (*var)
	{
		if (*var != '\'' && *var != '"')
			tmp += ((*tmp = *var, 1));
		++var;
	}
	return (no_quotes);
}
