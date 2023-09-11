#include "parse.h"

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
//	print_all_tokens(in->cmd_line);

	return (0);
}
