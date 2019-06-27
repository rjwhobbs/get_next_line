#include "libft.h"
#include <fcntl.h>
#include "get_next_line.h"

int		main(void)
{
	char 	*nline;
	int 	fd;
	int		i;
	int 	check;

	i = 0;
	check = 0;
	fd = open("war_and_peace.txt", O_RDONLY);
	while (get_next_line(fd, &nline) == 1)
	{
		ft_putendl(nline);
		//if (ft_strchr(nline, '\n'))
		//		ft_putendl("!!!!!!!");
		free(nline);
	}
	close(fd);
	return (0);
}
