#include "get_next_line.h"
#include "libft.h"

char	*ft_strrealloc(char *s1, char *s2)
{
	char *new;

	new = ft_strjoin(s1, s2);
	ft_strdel(&s1);
	return (new);
}

static int		temp_check(char **temp, char **line, char *del_temp)
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
		ft_strdel(&del_temp);
	}
	return (0);
}

void		buff_rw(char **temp, char **line, char *del_temp, int *end, char **nlp, int fd)
{
	char 		buff[BUFF_SIZE + 1];

	*end = read(fd, buff, BUFF_SIZE);
	buff[*end] = '\0';
	*nlp = ft_strchr(buff, '\n');
	if (*nlp)
	{
		**nlp = '\0';
		*temp = ft_strdup(*nlp + 1);
		del_temp = *temp;
	}
	*line = ft_strrealloc(*line, buff);
}

int	get_next_line(const int fd, char **line)
{
	//char 			buff[BUFF_SIZE + 1];
	char			*nlp;
	static int 		last_line;
	int				end;
	static char		*temp;
	static char		*del_temp;

	*line = ft_strnew(0);
	if (temp_check(&temp, line, del_temp))
		return (1);
	if (last_line == 1)
		return (0);
	end = BUFF_SIZE;
	while (end == BUFF_SIZE)
	{
		buff_rw(&temp, line, del_temp, &end, &nlp, fd);
		if (*nlp)
			return (1);
	/*	end = read(fd, buff, BUFF_SIZE);
		buff[end] = '\0';
		nlp = ft_strchr(buff, '\n');
		if (nlp)
		{
			*nlp = '\0';
			temp = ft_strdup(nlp + 1);
			del_temp = temp;
		}
		*line = ft_strrealloc(*line, buff);
		if (nlp)
			return (1);*/
	}
	if (end != BUFF_SIZE)
	{
		last_line++;
		return (0);
	}
	return (1);
}
