#include "minishell.h"

char	*str_token(t_type token)
{
	if (token == APPEND)
		return ("APPEND");
	else if (token == HEREDOC)
		return ("HEREDOC");
	else if (token == LIMITOR)
		return ("LIMITOR");
	else if (token == FD)
		return ("FD");
	else if (token == PIPE)
		return ("PIPE");
	else if (token == R_IN)
		return ("R_IN");
	else if (token == R_OUT)
		return ("R_OUT");
	else if (token == WORD)
		return ("WORD");
	return (NULL);		
}

void	print_all_words(t_token *cmd_line)
{
	t_token	*current;
	char	*token;

	current = cmd_line;
	while (current != 0)
	{
		token = str_token(current->type);
		printf("%s -------------- token = %s, token %d\n", current->word, token, current->type);
		current = current->next;
	}
}

void	delall(t_data *in)
{
	t_token	*ptr;

	while (in->cmd_line != NULL)
	{
		free(in->cmd_line->word);
		ptr = in->cmd_line;
		in->cmd_line = in->cmd_line->next;
		free(ptr);
	}
}

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_data	*in;
	int	split;

	printf("----------------TEST SPLIT WORDS----------------\n");
	in = ft_calloc(1, sizeof(t_data));
	while (1)
	{
		in->input = readline("");
		split = split_into_words(in);
		printf("SPLIT_INTO_WORDS RETURNS == %d\n", split);
		print_all_words(in->cmd_line);
		delall(in);
		if (ft_strncmp("STOP", in->input, 4) == 0)
			break ;
		free(in->input);
	}
	free(in->input);
	printf("--------------END TEST SPLIT WORDS--------------\n\n");
	free(in);

	return (0);
}
