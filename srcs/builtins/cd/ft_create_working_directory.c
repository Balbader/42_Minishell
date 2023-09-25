/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_working_directory.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:05:51 by baalbade          #+#    #+#             */
/*   Updated: 2023/09/24 15:05:52 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_create_working_directory(void)
{
	static const char	pwd[5] = "PWD=\0";
	char				*wd;
	char				*tmp;

	wd = getcwd(NULL, 0);
	tmp = wd;
	wd = ft_strjoin(pwd, wd);
	free(tmp);
	ft_add_to_env(wd);
	free(wd);
}
