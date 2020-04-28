#include<unistd.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>

int     ft_isprint(int c)
{
    if (c < 32 || c > 126)
        return (0);
    return (1);
}

int     main(void)
{
    printf("%d\n", isprint(126));
    printf("%d\n", ft_isprint(126));
}
