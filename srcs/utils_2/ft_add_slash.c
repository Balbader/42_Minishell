/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_slash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:15:20 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/25 17:15:22 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
** ft_strjoin_add_slash
** join S1 and S2
** and add '/' between us
** return NULL if error
** else return malloc char
*/
char	*ft_add_slash(char const *s1, char const *s2)
{
	int		i[3];
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	i[1] = ft_strlen((char *)s1);
	i[2] = ft_strlen((char *)s2);
	str = (char *)malloc(sizeof(char) * (i[1] + i[2] + 2));
	if (str == NULL)
		return (NULL);
	i[0] = -1;
	while (s1[++i[0]])
		str[i[0]] = s1[i[0]];
	i[0] = -1;
	str[i[1]++] = '/';
	while (s2[++i[0]])
	{
		str[i[1]] = s2[i[0]];
		i[1]++;
	}
	str[i[1]] = '\0';
	return (str);
}
