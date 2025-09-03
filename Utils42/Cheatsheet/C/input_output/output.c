#include <stdio.h>

int main(void)
{
    int x = printf("%d", 1234); // return the number of character printed on the screen
    printf("%d", x);
    return 0;
}