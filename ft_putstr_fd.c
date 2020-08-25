#include<unistd.h>
#include<stdio.h>
#include<string.h>

void	ft_putstr_fd(char *s, int fd)
{
	int	length;

	count = 0;
	while (s[length] != '\0')
		length++;
	write(fd, s, length);
}
