#include<unistd.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>

int     ft_isascii(int c)
{
    if (c < 0 || c > 127)
        return (0);
    return (1);
}

int     main(void)
{
    printf("%d \n", isascii(-1));
    printf("%d \n", ft_isascii(-1));
}
