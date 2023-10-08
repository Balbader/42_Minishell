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
		// printf("''%s'' -------------- token = %s, token %d\n", current->word, token, current->type);
		current = current->next;
	}
}

void	print_cmd_nodes(t_cmd *cmd)
{
	t_cmd *ptr;
	int i = 0;

	ptr = cmd;
	while (ptr != NULL)
	{
		// printf("-----CMD_NODE[%d]-----\n", i);
		if (ptr->args)
			print_all_words(cmd->args);
		if (ptr->rdir)
			print_all_words(cmd->rdir);
		ptr = ptr->next;
		i++;
	}
}

int	ft_printenv(t_env *new_env)
{
printf("-----------TEST ENV----------");
	while (new_env)
	{
		printf("var : %s\n", new_env->var);
		printf("key : %s\n", new_env->key);
		printf("value : %s\n", new_env->value);
		new_env = new_env->next;
	}
printf("-------END TEST ENV----------");
	return (0);
}

void	print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		printf("tab[%d] = |%s|\n", i, tab[i]);
		i++;
	}
}
