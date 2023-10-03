//#include "minishell.h"
#include <stdio.h>

int	ft_get_tab_len(char **tab)
{
	int	i;

	if (!tab)
		return (0);
	i = 0;
	while (tab[i])
		++i;
	return (i);
}

int	ft_get_word_len(char *str, int i)
{
	int	wd_len;

	wd_len = 0;
	while (str[i] != ' ' || str[i] != '\t')
	{
		++wd_len;
		++i;
	}
	return (wd_len);
}

int	ft_get_space_len(char *str, int i)
{
	int	len;

	len = 0;
	while (str[i] == ' ')
	{
		++len;
		++i;
	}
	return (len);
}

int	ft_get_wd_count(char *str)
{
	int	wd_count;
	int	i;

	wd_count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			 ++wd_count;
		while (str[i] && str[i] == ' ')
			++i;
		if (str[i])
			++wd_count;
		while (str[i] && str[i] != ' ')
			++i;
	}
	return (wd_count);
}

char	**sep_word_space(char *str)
{
	char			**final;
	static int		i;

	i = 0;
	return (final);
}

int main(void)
{
	char	*str = "     $USER         A$ $?      $/"; // == 8
	// char	*str = "     $USER         A$ $?      $/        "; // == 9 
	// char	*str = "$USER         A$ $?      $/"; // == 7
	// char	*str = "     $USER         A$ $?"; // == 6
	// char	**tab = NULL;
	// int		tab_len;
	int		wd_count;

	// tab_len = ft_get_tab_len(tab);
	// tab = sep_word_space(str);
	wd_count = ft_get_wd_count(str);
	printf("wd_count : %d\n", wd_count);
	// for (int i = 0; i < tab_len; ++i) {
	// 	printf("%s\n", tab[i]);
	// }
	return (0);
}
