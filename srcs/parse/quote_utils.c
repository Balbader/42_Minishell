/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:58:03 by ftuernal          #+#    #+#             */
/*   Updated: 2023/09/18 14:11:44 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//This function screens inputs for having correctly closed quotes
bool	check_quotes(char *input)
{
	bool	singl_open;
	bool	doubl_open;
	int		i;

	i = -1;
	singl_open = false;
	doubl_open = false;
	while (input[++i])
	{
		if (input[i] == '\'' && doubl_open == false)
			singl_open = !singl_open;
		else if (input[i] == '\"' && singl_open == false)
			doubl_open = !doubl_open;
	}
	return (!singl_open && !doubl_open);
}
/*
int	main(int ac, char **av)
{
	char *str;

	(void)av;
	str = "$> echo \"'$'\"\"\""; 
	if (ac != 1)
		return (0);
	if (check_quotes(str))
		printf("%s is correct\n", str);
	else
		printf("%s IS NOT correct\n", str);
	return (0);
}
*/

bool	quote_on(const char *input, int index)
{
	int	i;
	bool	simplq_on;
	bool	doublq_on;

	simplq_on = false;
	doublq_on = false;
	i = 0;
	while (i < index)
	{
		if (input[i] == '\'' && input[i + 1] != '\'' && doublq_on == false)
			simplq_on = !simplq_on;
		else if (input[i] == '\"' && simplq_on == false)
			doublq_on = !doublq_on;
		else if (input[i] == '\'' && input[i + 1] == '\'' && simplq_on == false)
			doublq_on = !doublq_on;
		i++;
	}
	return (simplq_on || doublq_on);
}
