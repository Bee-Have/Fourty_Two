#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>

int		ft_toupper(int c)
{
	if (!c)
		return (0);
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
