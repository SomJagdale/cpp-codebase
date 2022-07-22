//C program t illustrate scanf statement
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a[10],b[20];
    printf("Please enter your name : \n");

    //scanf statement
    scanf("%s", a,b);

    printf("You entered: \n%s  and b is %s", a,b);

    return 0;
}
