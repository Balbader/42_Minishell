/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:21:07 by ftuernal          #+#    #+#             */
/*   Updated: 2023/09/20 15:18:48 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*join_free(char *s1, char *s2, char *ptr)
{
	char	*join;

//printf("s1 = %p | s2 = %p ptr = %p\n", s1, s2, ptr);
	join = ft_strjoin(s1, s2);
	if (!join)
		return (NULL);
	free(ptr);
	return (join);
}
