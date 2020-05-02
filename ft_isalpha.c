#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int		ft_isalpha(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}
