#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	*calloc(size_t count, size_t size)
{
	char *cp;

	cp = (char *)malloc(count * size);
	if (!cp)
		return (NULL);
	return (cp);
}
