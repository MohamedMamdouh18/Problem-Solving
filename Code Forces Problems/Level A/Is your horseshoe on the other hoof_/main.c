#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[4] , num = 4 ;
    scanf("%i %i %i %i" , &a[0] , &a[1] , &a[2] , &a[3]) ;
    for(int i = 0 ; i < 3 ; i ++)
    {
        for(int j = i + 1 ; j < 4 ; j ++)
        {
            if(a[i] == a[j] )
            {
                num -- ;
                a[j] = -j ;
            }
        }
    }
    printf("%i" , 4 - num) ;
}
