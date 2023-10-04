char	*trim_last_space(char *word)
{
	char	*new_str;
	int		len;
	int		i;

	ptr = *node;
	len = (int)ft_strlen(word);
	new_str = ft_calloc(len, sizeof(char));
	if (!new_str)
		return ;
	new_str[len] = 0;
	i = len - 1;
	while (i >= 0)
	{
		new_str[i] = ptr->word[len - 2];
		
	}
	
}
