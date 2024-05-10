#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char str[100];
int i, len;

int X()
{
    if(i == len - 1)
    {
        return 1;
    }
    else if(i < len - 1 && str[i] == 'b' && str[i + 1] == 'b')
    {
        i += 2;

        return X();
    }
    else if(i < len - 1 && str[i] == 'b' && str[i + 1] == 'c')
    {
        i += 2;

        return X();
    }
    else
        return 0;
}

int A()
{
    if(str[0] == 'a')
    {
        i = 1;

        if(X())
        {
            if(str[len-1] == 'd')
                return 1;
            else
                return 0;
        }

        return 0;
    }

    return 0;
}

int main(void)
{
    gets(str);
    len = strlen(str);

    if(A())
    {
        printf("Accepted by Grammar.\n");
    }
    else
    {
        printf("Rejected by Grammar.\n");
    }

    return 0;
}
