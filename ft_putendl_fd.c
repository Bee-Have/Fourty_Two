#include<unistd.h>
#include<stdio.h>
#include<string.h>

void	ft_putendl_fd(char *s, int fd)
{
	int	i;
	int	length;

	length = 0;
	while (s[length] != '\0')
		length++;
	write(fd, result, length);
	write(fd, '\n', 1);
}
