#include "minishell.h"

void	print_all_words(t_token *cmd_line)
{
	t_token	*current;

	current = cmd_line;
	while (current != 0)
	{
		printf("%s\n", current->word);
		current = current->next;
	}
}

void	delall(t_token *cmd_line)
{
	t_token	*ptr;

	while (cmd_line != NULL)
	{
		free(cmd_line->word);
		ptr = cmd_line;
		cmd_line = cmd_line->next;
		free(ptr);
	}
}

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	char	*input;
	t_token **cmd_line;
	int	split;

	cmd_line = ft_calloc(1, sizeof(t_token));
	printf("----------------TEST SPLIT WORDS----------------\n");
	while (1)
	{
		input = readline("");
		split = split_into_words(*cmd_line, input);
		printf("SPLIT_INTO_WORDS RETURNS == %d\n", split);
		print_all_words(*cmd_line);
		delall(*cmd_line);
		if (ft_strncmp("STOP", input, 4) == 0)
			break ;
		free(input);
	}
	free(input);
	printf("--------------END TEST SPLIT WORDS--------------\n\n");
//	print_all_tokens(in->cmd_line);

	return (0);
}
