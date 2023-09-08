/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sep_cmd_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:44:30 by ftuernal          #+#    #+#             */
/*   Updated: 2023/09/06 16:07:53 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//------------------------------------draft not yet tested--------------------

#include "parse.h"

int	sep_cmd_line(t_data *in)
{
	int		i;
	int		start;

	i = -1;
	start = 0;
	while (in->input[++i])
	{
		if ((in->input[i] == '|' && !quote_on(in->input, i)) || in->input[i + 1] == '\0')
		{
			if (append_cmd_node(in, start, i + 1 - start) == FAILURE)
				return (FAILURE);
			start += i - start + 1;
		}
	}
	return (SUCCESS);
}
///////////////////////////////////////////////////
///////////////////////////////////////////////////
//DEBUG--------------------------------------------
void	print_all_nodes(t_cmdlst *cmd_line)
{
	while (cmd_line->next != NULL)
	{
		printf("CMD_LINE == %s\n", cmd_line->line);
		cmd_line = cmd_line->next;
	}
	printf("CMD_LINE == %s\n", cmd_line->line);
}

void	print_all_words(t_cmdlst *cmd_line)
{
	while (cmd_line->next != NULL)
	{
		printf("CMD_LINE == %s\n", cmd_line->line);
		printf("WORDS\n___\n");
		while (cmd_line->words != NULL)
		{
			printf("%s\n", cmd_line->words->word);
			cmd_line->words = cmd_line->words->next;
		}
		printf("%s\n", cmd_line->words->word);
		printf("___\n");
		cmd_line = cmd_line->next;
	}
	printf("CMD_LINE == %s\n", cmd_line->line);
}
/*
void	del_all_words(t_cmdlst *cmd_line)
{
	t_token	*temp;

	while (cmd_line->words != NULL)
	{
		free(cmd_line->words->word);
		temp = cmd_line->words;
		cmd_line->words = cmd_line->words->next;
		free(temp);
	}
}
*/
void	del_all_nodes(t_data *in)
{
	t_cmdlst	*temp;

	while (in->cmd_line != NULL)
	{
		free(in->cmd_line->line);
//		del_all_words(in->cmd_line);
		temp = in->cmd_line;
		in->cmd_line = in->cmd_line->next;
		free(temp);
	}
}

int	main(int ac, char **av)
{
	t_data *in;

	(void)ac;
	in = ft_calloc(1, sizeof(t_data));
	if (alloc_parse_struct(in) == FAILURE)
	{
		printf("alloc failed\n");
		return (0);
	}
	in->input = ft_strdup(av[1]);
printf("-----------------------START OF SEP_CMD_LINE TEST----------------------\n");
	sep_cmd_line(in);
	print_all_nodes(in->cmd_line);
printf("-----------------------END OF SEP_CMD_LINE TEST----------------------\n");
/*
printf("-----------------------START OF SEP_IN_WORDS TEST----------------------\n");
printf("in->cmd_line ptr = %p\n", in->cmd_line);
	sep_in_words(in);
	print_all_words(in->cmd_line);
printf("-----------------------END OF SEP_IN_WORDS TEST----------------------\n");
*/
//free all allocs
	free(in->input);
	del_all_nodes(in);
	free(in->cmd_line);
	free(in);
	return (0);
}
