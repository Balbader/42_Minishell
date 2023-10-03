/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sep_word_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:26:49 by baalbade          #+#    #+#             */
/*   Updated: 2023/10/03 15:26:51 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

int	ft_get_wd_count(char *str)
{
	int	wd_count;
	int	i;

	wd_count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			 ++wd_count;
		while (str[i] && str[i] == ' ')
			++i;
		if (str[i])
			++wd_count;
		while (str[i] && str[i] != ' ')
			++i;
	}
	return (wd_count);
}

char	*ft_strdup(char *str)
{
	char	*dup;
	size_t	str_len;
	size_t	i;
	size_t	j;

	if (!str)
		return (NULL);
	str_len = ft_strlen(str);
	dup = (char *)malloc(sizeof(char) * (str_len + 1));
	if (!dup)
		return (NULL);
	j = 0;
	i = 0;
	while (str[i])
		dup[j++] = str[i++];
	dup[j] = '\0';
	return (dup);
}

char	*ft_substr(char *s, int start, int len)
{
	char			*substr;
	int	i;

	i = 0;
	if (s == NULL || start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	while (s[start] && i < len)
	{
		substr[i] = s[start];
		start++;
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

int	ft_is_var_char(char c)
{
	if (c == '_' || (c >= 'a' && c <= 'z') ||
			(c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

char	**sep_word_space(char *str)
{
	char	**final;
	int		wd_count;
	int		tmp;
	int		i;
	int		j;

	wd_count = ft_get_wd_count(str);
	final = (char **)malloc(sizeof(char *) * (wd_count + 1));
	if (!final)
		return (NULL);
	j = 0;
	i = 0;
	tmp = i;
	while (str[i])
	{
		if (str[i] == '$')
		{

			final[j] = ft_substr(str, tmp, i);
			printf("final[%d] : |%s|\n", j, final[j]);
			++j;
			printf("j : %d\n", j);
			tmp = i;
			printf("tmp : %d\n", tmp);
			++i;

			//==========================================

			while (ft_is_var_char(str[i]) == 1)
				++i;
			final[j] = ft_substr(str, tmp, i);
			printf("final[%d] : |%s|\n", j, final[j]);
			tmp = i;
			printf("tmp : %d\n", tmp);
			++j;
			printf("j : %d\n", j);

		}
		++i;
	}
	final[j] = "\0";
	return (final);
}

int main(void)
{
	// char	*str = "$USER        A$ $?   $/";
	char	*str = "     $USER        A$ $?   $/";
	char	**tab = NULL;
	int		wd_count;

	wd_count = ft_get_wd_count(str);
	printf("wd_count : %d\n", wd_count);
	tab = sep_word_space(str);
	for (int i = 0; i <= wd_count; ++i) {
		printf("tab[%d] : |%s|\n", i, tab[i]);
	}
	return (0);
}
