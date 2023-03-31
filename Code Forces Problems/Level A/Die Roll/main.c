#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a , b , bigger , divisor;
    scanf("%i %i" , &a , &b) ;

    if(a >= b)
    {
        bigger = a ;
    }
    else
    {
        bigger = b ;
    }

    int num = 7 - bigger ;

    for (int i = 1 ; i <= num ; i ++)
    {
        if(num % i == 0 && 6 % i == 0)
        {
            divisor = i ;
        }
    }
    printf("%i/%i" , num/divisor , 6/divisor) ;
}
