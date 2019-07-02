#include "get_next_line.h"

static char	*ft_strrealloc(char *s1, char *s2)
{
	char *new;

	new = ft_strjoin(s1, s2);
	ft_strdel(&s1);
	return (new);
}

static int	temp_check(char **temp, char **line, char **del_temp)
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
			if (!*line)
				return (-1);
			*temp = (nlp + 1);
			return (1);
		}
		*line = ft_strrealloc(*line, *temp);
		if (!*line)
			return (-1);
		ft_strdel(del_temp);
	}
	return (0);
}

static int	buff_rw(t_gnl *gnl, char **line, int fd)
{
	char	buff[BUFF_SIZE + 1];
	int		end;

	end = read(fd, buff, BUFF_SIZE);
	if (end < 0)
		return (end);
	buff[end] = '\0';
	gnl->nlp = ft_strchr(buff, '\n');
	if (gnl->nlp)
	{
		*gnl->nlp = '\0';
		gnl->temp = ft_strdup(gnl->nlp + 1);
		if (!gnl->temp)
			return (-1);
		gnl->del_temp = gnl->temp;
	}
	*line = ft_strrealloc(*line, buff);
	if (!*line)
		return (-1);
	return (end);
}

int			get_next_line(const int fd, char **line)
{
	static t_gnl	gnl;
	int				end;

	if (BUFF_SIZE < 1 || !line)
		return (-1);
	*line = ft_strnew(0);
	if (!*line)
		return (-1);
	if (temp_check(&gnl.temp, line, &gnl.del_temp))
		return (1);
	end = BUFF_SIZE;
	while (end == BUFF_SIZE)
	{
		end = buff_rw(&gnl, line, fd);
		if (end < 0)
			return (-1);
		if (gnl.nlp)
			return (1);
	}
	if (end == 0)
		return (0);
	return (1);
}
