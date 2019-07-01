#include "libft.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "get_next_line.h"

int		main(int ac, char **av)
{
	char 	*nline;
	int 	fd;
	int		fd2;
	int		status;
	int		a;
	int		sec;

	a = ac;
	sec = ft_atoi(av[3]);
	ft_putendl("Opening a file...");
	if ((fd = open(av[1], O_RDONLY)) < 0)
	{
		ft_putendl("   Error opening a file...");
		return (0);
	}
	if ((fd2 = open(av[2], O_CREAT | O_WRONLY)) < 0)
	{
		ft_putendl("   Error opening a file...");
		close(fd);
		return (0);
	}
	chmod(av[2], 0700);
	ft_putendl("File openning succeeded");

	ft_putendl("Started reading");
	while ((status = get_next_line(fd, &nline)) == 1)
	{
		ft_putendl("   Writing to output file...");
		ft_putendl_fd(nline, fd2);
		free(nline);
	}
	if (status == 0)
	{
		ft_putendl("End of file reached...");
	}
	else
	{
		ft_putendl("Something went wrong in get_next_line...");
	}
	ft_putendl("Closing files...");
	ft_putstr("Check for leaks, you have: ");
	ft_putnbr(sec);
	ft_putendl(" seconds.");
	close(fd);
	close(fd2);
	sleep(sec);
	return (0);
}
