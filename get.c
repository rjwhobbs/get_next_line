#include "libft.h"
#include <fcntl.h>
#include <stdio.h>
#define BUFF_SIZE 20

int		safe_len(const char *s1)
{
	int i;

	i = 0;
	if (!s1)
		return (0);
	while(s1[i])
		i++;
	return (i);
}

char	*join(char const *s1, char const *s2)
{
	int		len;
	char	*newstring;
	char	*temp;

	len = 0;
	len = safe_len(s1) + safe_len(s2);
	if (!(newstring = (char*)malloc(sizeof(*newstring) * (len + 1))))
		return (NULL);
	temp = newstring;
	if (safe_len(s1))
	{	
		while (*s1)
		{
			*newstring = *s1++;
			newstring++;
		}
	}
	while (*s2)
	{
		*newstring = *s2++;
		newstring++;
	}
	*newstring = '\0';
	newstring = temp;
	return (newstring);
}

int		line(const char s1)
{
	if (s1 == '\n')
		return (0);
	else
		return (1);
}

int		get(const int fd, char **line)
{
	static char		buff[BUFF_SIZE + 1];
	int				i;
	int				end;
	static int		last_line;
	static int		check;
	static char		*temp;

	if (last_line == 1)
		return (0);
	i = 0;
	end = read(fd, buff, BUFF_SIZE);
	if (end == BUFF_SIZE)
	{
		buff[BUFF_SIZE] = '\0';
		*line = ft_strdup(buff);
		return (1);
	}
	if (end < BUFF_SIZE)
		buff[end] = '\0';
	*line = ft_strdup(buff);
	if (end < BUFF_SIZE)
		last_line++;
	return (1);
}

int		main(void)
{
	char 	*nline;
	int 	fd;

	fd = open("war_and_peace.txt", O_RDONLY);
	while (get(fd, &nline) == 1)
	{
		ft_putstr(nline);
	}
	close(fd);
	return (0);
}
