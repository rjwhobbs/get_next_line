#include "get_next_line.h"
#include "libft.h"

char	*ft_strrealloc(char *s1, char *s2)
{
	char *new;

	new = ft_strjoin(s1, s2);
	free(s1);
	return (new);
}

int	get_next_line(const int fd, char **line)
{
	char 			buff[BUFF_SIZE + 1];
	static int 		last_line;
	size_t			end;
	char			*nlp;
	static char		*temp;

	*line = ft_strnew(0);
	if (temp)
		*line = ft_strrealloc(*line, temp);
	if (last_line == 1)
		return (0);
	end = BUFF_SIZE;
	while (end == BUFF_SIZE)
	{
		end = read(fd, buff, BUFF_SIZE);
		buff[end] = '\0';
		nlp = ft_strchr(buff, '\n');
		if (nlp)
		{
			*nlp = '\0';
			temp = ft_strdup(nlp + 1);
		}
		*line = ft_strrealloc(*line, buff);
		if (nlp)
			return (1);
	}
	if (end != BUFF_SIZE)
		last_line++;
	return (1);
}
