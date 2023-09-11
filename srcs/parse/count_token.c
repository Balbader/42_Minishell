#include "parse.h"

int	count_token(char *line)
{
	int	count;
	int	start;
	int	i;
	int	end;

	i = 0;
	count = 0;
	while (i < (int)ft_strlen(line))
	{
		start = set_start_word(line, i);
		end = set_end_word(line, start);
		while (i <= end && line[i])
			i++;
//printf("string == %s start == %d end == %d\n", line + start, start, end);
		count++;
	}
	return (count + 1);
}
/*
int	main(void)
{
	char	*line = "coucou \"ca va \" \"| \"la fete |>";
//	char	*line = " | > << >>| <<<|";
//	printf("line == %s\n", line);
//	char	*line = "\"file\".c";
	printf("%d\n", count_token(line));
	return (0);
}
*/
