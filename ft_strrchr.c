#include<stdio.h>
#include<unistd.h>
#include<string.h>

char    *ft_strrchr(char *s, int c)
{
    int i;
    int oc;

    i = 0;
    oc = 0;
    while (s[i] != '\0')
    {
        if (s[i] == c)
            oc = i;
        i++;
    }
    if (oc == 0 && s[oc] != c)
        return (NULL);
    return (&s[oc]);
}

int     main(void)
{
    char *str = {"Hello There General Kenobi!"};

    printf("%s\n", strrchr(str, 'H'));
    printf("%s\n", ft_strrchr(str, 'H'));
}
