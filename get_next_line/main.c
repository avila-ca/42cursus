#include "get_next_line.h"

int main(void)
{
	int	fd;
	int print;
	int i;

	i = 0;
	fd = open("test.txt", O_RDONLY);
	while(i < 4)
	{
		printf("%s", get_next_line(fd));
		i++;
	}
	close(fd);
	return (0);
}
