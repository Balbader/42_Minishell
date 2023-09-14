#include "expand.h"

char	*join_all_str(char **split)
{
	int		i;
	char	*joined_str;

	i = -1;
	joined_str = ft_calloc(1, sizeof(char));
	if (!joined_str)
		return (NULL);
	while (split[++i])
	{
		joined_str = join_free(joined_str, split[i], joined_str);
		if (!joined_str)
			return (NULL);
	}
	return (joined_str);
}

void	replace_var_by_value(char **ptr)
{
	t_env	*env;
	int		i;
	int		last_ret;
	char	*value;

	if (split[i] == '?')
	{
		*ptr += 1;
		last_ret = search_last_ret();
		value = ft_itoa(last_ret);
	}
	else
	{}
	*ptr = join_free(value, *ptr, *ptr);
	free(value);
	env = get_env();
}

char	*expand_var(char *word)
{
	int		i;
	char	**split;
	char	*expand_word;

	split = ft_split(word, '$');
	if (!split)
		return (0);
	i = -1;
	while (split[++i])
	{
		if (ft_isspace(split[i]) != 0)
		{
			split[i] = join_free("$", split[i], split[i]);
			if (!split[i])
				return (free_2char_str(split), NULL);
		}
		else if (ft_isspace(split[i]) == 0)
			replace_var_by_value(&split[i]);
	}
	expand_word = join_all_str(split);
	return (free_2char_str(split), expand_word);
}
