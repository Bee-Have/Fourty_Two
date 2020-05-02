#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int		ft_isascii(int c)
{
	if (c < 0 || c > 127)
		return (0);
	return (1);
}
