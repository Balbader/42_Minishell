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

char	*replace_by_last_ret(char *word)
{
	char	*new_str;
	int		last_ret;
	char	*ascii_ret;

	new_str = ft_calloc(ft_strlen(word), sizeof(char));
	if (!new_str)
		return (NULL);
	new_str = ft_strcpy(word + 1);
	last_ret = get_last_ret_val();
	ascii_ret = ft_itoa(last_ret);
	if (!ascii_ret)
		return (free(new_str), NULL);
	new_str = join_free(ascii_ret, new_str, new_str);
	free(ascii_ret);
	return (new_str);
}

void	replace_var_by_value(char **ptr)
{
	t_env	*env;
	char	*new_str;
	int		i;

	if (split[i] == '?')
	{
		new_str = replace_by_last_ret(*ptr);
		if (!new_str)
			return ;
		*ptr += 1;
	}
	else
	{
		env = get_env();
		new_str = replace_by_env_value(*ptr, env);
	}
	*ptr = new_str;
	free(new_str);
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
