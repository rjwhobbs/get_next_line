#include "get_next_line.h"

char	*ft_strrealloc(char *s1, char *s2)
{
	char *new;

	new = ft_strjoin(s1, s2);
	ft_strdel(&s1);
	return (new);
}

static int		temp_check(char **temp, char **line, char **del_temp)
{
	char *nlp;

	nlp = NULL;
	if (*temp)
	{
		nlp = ft_strchr(*temp, '\n');
		if (nlp)
		{
			*nlp = '\0';
			*line = ft_strrealloc(*line, *temp);
			*temp = (nlp + 1);
			return (1);
		}
		*line = ft_strrealloc(*line, *temp);
		ft_strdel(del_temp);
	}
	return (0);
}

int		buff_rw(char **temp, char **line, char **del_temp, char **nlp, int fd)
{
	char 		buff[BUFF_SIZE + 1];
	int			end;
	
	end = read(fd, buff, BUFF_SIZE);
	buff[end] = '\0';
	*nlp = ft_strchr(buff, '\n');
	if (*nlp)
	{
		**nlp = '\0';
		*temp = ft_strdup(*nlp + 1);
		*del_temp = *temp;
	}
	*line = ft_strrealloc(*line, buff);
	return (end);
}

int	get_next_line(const int fd, char **line)
{
	char			*nlp;
	int				end;
	static char		*temp;
	static char		*del_temp;

	*line = ft_strnew(0);
	if (temp_check(&temp, line, &del_temp))
		return (1);
	end = BUFF_SIZE;
	while (end == BUFF_SIZE)
	{
		end = buff_rw(&temp, line, &del_temp, &nlp, fd);
		if (nlp)
			return (1);
	}
	if (end != BUFF_SIZE)
		return (0);
	return (1);
}