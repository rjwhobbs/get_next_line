#include "libft.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "get_next_line.h"

int		main(void)
{
	char 	*nline;
	int 	fd;
	int		fd2;
	int		file_length;
	int		txt_file_length;
	char	len_check[1];
	int		new_line_check;
	int		line_length;
/*
	txt_file_length = 0;
	file_length = 0;
	new_line_check = 0;
	line_length = 0;

	fd = open("10_char_lines.txt", O_RDONLY);
	while (read(fd, len_check, 1))
			txt_file_length++;
	close(fd);
	
	fd = open("10_char_lines.txt", O_RDONLY);
	while (get_next_line(fd, &nline) == 1)
	{
		ft_putstr(nline);
		ft_putendl_fd(nline, fd2);
		if (nline)
		{
			ft_nl();
			line_length = ft_strlen(nline);
			if (nline[line_length] == '\0')
				file_length++;
		}
		file_length += line_length;
		if (ft_strchr(nline, '\n'))
			new_line_check++;
		free(nline);
	}
	ft_nl();
	ft_putstr("File length: ");
	ft_putnbr(file_length);
	ft_nl();
	ft_putstr("GNL length:  ");
	ft_putnbr(file_length);
	ft_nl();
	ft_putstr("Newlines: ");
	ft_putnbr(new_line_check);
	ft_nl();
	close(fd);
*/

	int		status;

	ft_putendl("Opening a file...");
	if ((fd = open("10_char_lines.txt", O_RDONLY)) < 0)
	{
		ft_putendl("   Error opening a file...");
		return (0);
	}
	if ((fd2 = open("output", O_CREAT | O_WRONLY)) < 0)
	{
		ft_putendl("   Error opening a file...");
		close(fd);
		return (0);
	}
	chmod("output", 0700);
	ft_putendl("File openning succeeded");

	ft_putendl("Started reading");
	while ((status = get_next_line(fd, &nline)) == 1)
	{
		ft_putendl("   Writing to output file...");
		ft_putendl_fd(nline, fd2);
	}
	if (status == 0)
	{
		ft_putendl("End of file reached...");
		//ft_pute_fd(nline, fd2);
	}
	else
	{
		ft_putendl("Something went wrong in get_next_line...");
	}
	ft_putendl_fd(nline, fd2);
	ft_putendl_fd(nline, fd2);
	ft_putendl_fd(nline, fd2);
	ft_putendl_fd(nline, fd2);
	ft_putendl("Closing files...");
	close(fd);
	close(fd2);
	execl("/bin/diff");
	return (0);
}
