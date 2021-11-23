#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include "libft.h"


int	get_next_line(const int fd, char **line)
{
	//read
	int		b_read;

	b_read = 1;

	*line = (char*)malloc(BUFF_SIZE);

	while (b_read != 0)
	{
		b_read = read(fd, &*line, BUFF_SIZE);
		if (b_read != 0)
			write(1, &*line, 1);
	}
	return (0);
}

int main()
{
	int fd;
	char **line = NULL;

	fd = open("testifilu", O_RDWR | O_CREAT);
	ft_putstr_fd("Hello world!", fd);
	printf("%d", get_next_line(fd, line));
	printf("%s", *line);
	close(fd);
	free (*line);
	return 0;
}
