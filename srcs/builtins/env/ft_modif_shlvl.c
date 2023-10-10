/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modif_shlvl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 11:14:18 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/24 11:14:20 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_modif_shlvl(void)
{
	static const char	str[7] = "SHLVL=\0";
	char				*shlvl;
	char				*tmp;
	int					lvl;

	shlvl = ft_find_value("SHLVL");
	if (!shlvl)
		return ;
	lvl = ft_atoi(shlvl);
	ft_del_from_env("SHLVL");
	++lvl;
	tmp = ft_itoa(lvl);
	shlvl = ft_strjoin(str, tmp);
	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!shlvl : %s\n", shlvl);
	free(tmp);
	ft_add_to_env(shlvl);
	free(shlvl);
}
