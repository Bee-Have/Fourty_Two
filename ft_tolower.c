#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>

int		ft_tolower(int c)
{
	if (!c)
		return (0);
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
