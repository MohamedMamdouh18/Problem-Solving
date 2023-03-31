#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a , b , i = 0 ;
    scanf("%i %i" , &a, &b);
    while(a <= b)
    {
        a = a * 3 ;
        b = b * 2 ;
        i ++ ;
    }
    printf("%i" , i) ;
}
