#include "libft.h"
#include <fcntl.h>
#include <stdio.h>
#define BUFF_SIZE 20

char	*ft_strnjoin(const char *s1, const char *s2, size_t n)
{
	int		len;
	char	*newstring;
	char	*temp;
	int		i;

	i = 0;
	len = 0;
	len = ft_strlen(s2);
	if (!(newstring = (char*)malloc(sizeof(*newstring) * (len + n + 1))))
		return (NULL);
	temp = newstring;
	while (i < n)
	{
		*newstring = *s1++;
		newstring++;
		i++;
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

int		get_next_line(const int fd, char **line)
{
	static char		buff[BUFF_SIZE + 1];
	static int		i;
	int				end;
	static int		last_line;
	static int		check;
	static char		*temp;

	if (check == 1)
	{
		*line = ft_strdup(&buff[i]);
		check = 2;
	}
	if (last_line == 1)
		return (0);
	i = 0;
	end = read(fd, buff, BUFF_SIZE);
	if (end == BUFF_SIZE)
	{
		buff[BUFF_SIZE] = '\0';
		while (i < BUFF_SIZE)
		{
			if (buff[i] == '\n')
				break;
			i++;
		}
	}
	if (buff[i] == '\n')
	{
		buff[i] = '\0';
		*line = ft_strdup(buff);
		check = 1;
		buff[BUFF_SIZE] = '\0';
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

	fd = open("new_line.txt", O_RDONLY);
	while (get_next_line(fd, &nline) == 1)
	{
		ft_putendl(nline);
	}
	close(fd);
	return (0);
}
